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
    if (args.size() >= 2) {
        int task_number = args[1].toInt();
        if (!tasks.contains(task_number)) {
            return "task_not_found\r\n";
        }
        return QString("TASK %1 %2 %3 %4\r\n")
            .arg(task_number)
            .arg(tasks[task_number].a)
            .arg(tasks[task_number].b)
            .arg(tasks[task_number].k);
    }
    return "get_task_error\r\n";
}

QString solve_task(QStringList args, int socket_descriptor) {
    Database* db = Database::getInstance();
    if (args.size() >= 3) {
        int task_number = args[1].toInt();
        double answer = args[2].toDouble();
        bool is_correct = check_task(tasks[task_number], answer);
        if (!tasks.contains(task_number)) {
            return "task_not_found\r\n";
        }
        db->update_stat(task_number, socket_descriptor,is_correct);
        return is_correct ? "answer_correct\r\n" : "answer_incorrect\r\n";
    }
    return "solve_task_error\r\n";
}

bool check_task(Task task, double answer)
{
    double correct = (task.b - task.a) / std::pow(2.0, task.k);
    return std::abs(correct - answer) < 1e-6;
}
