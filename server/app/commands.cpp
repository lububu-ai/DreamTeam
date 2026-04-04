#include "commands.h"

QString register_user(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    if (args.size() >= 4){
        if(db->is_reg_ok(args[1], args[2], args[3], socket_descriptor)) {
            return "reg_success\r\n";
        }
    }
    return "reg_fail\r\n";
}

QString login(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    if (args.size() >= 3) {
        if (db->is_auth_ok(args[1], args[2], socket_descriptor)) {
            return "log_success\r\n";
        }
    }
    return "log_fail\r\n";
}

QString logout(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    if (db->log_out(socket_descriptor)) {
        return "logout_success\r\n";
    }
    return "logout_fail\r\n";
}

QString get_current_stat(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    return db->get_current_stat(socket_descriptor);
}

QString get_all_stat(QStringList args, int socket_descriptor)
{
    Database* db = Database::getInstance();
    return db->get_all_stat(socket_descriptor);
}

QString get_task(QStringList args, int socket_descriptor) {
    Database* db = Database::getInstance();
    if(args.size() < 2) {
        return "get_task_error\r\n";
    }
    if (!db->is_connected(socket_descriptor)) {
        return "not_authenticated\r\n";
    }
    int task_type = args[1].toInt();
    if (task_type < 1 || task_type > 5) {
        return "task_not_found\r\n";
    }
    CurrentTask current = db->get_current_task(socket_descriptor);
    if (current.is_valid() && current.type == task_type) {
        return QString("TASK %1 %2\r\n").arg(current.type).arg(current.payload);
    }
    CurrentTask new_task = generate_task(task_type);
    if (!new_task.is_valid()) {
        return "task_generation_error\r\n";
    }
    if (!db->save_current_task(socket_descriptor, new_task)) {
        return "task_save_error\r\n";
    }
    return QString("TASK %1 %2\r\n").arg(new_task.type).arg(new_task.payload);
}

QString solve_task(QStringList args, int socket_descriptor) {
    Database* db = Database::getInstance();
    CurrentTask task = db->get_current_task(socket_descriptor);
    if (args.size() >= 3 && db->is_connected(socket_descriptor) && task.is_valid()) {
        int task_number = args[1].toInt();
        double answer = args[2].toDouble();
        if (task_number < 1 || task_number > 5 || task_number != task.type) {
            return "task_not_found\r\n";
        }
        bool is_correct = std::abs(task.answer - answer) < 1e-3;
        db->update_stat(task_number, socket_descriptor, is_correct);
        db->clear_current_task(socket_descriptor);
        return is_correct ? "answer_correct\r\n" : "answer_incorrect\r\n";
    }
    return "solve_task_error\r\n";
}
