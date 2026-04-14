#include "database.h"

DatabaseDestroyer::~DatabaseDestroyer()
{
    delete p_instance;
}

void DatabaseDestroyer::initialize(Database * p){
    p_instance = p;
};

Database * Database::p_instance;
DatabaseDestroyer Database::destroyer;

Database::Database(){
    //подключение к бд
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("SQLite.db");

    if(!db.open())
        qDebug()<<db.lastError().text();
    //если таблица отсутсвует, то создать

    QSqlQuery query(db);
    //создали таблицу
    query.exec("CREATE TABLE IF NOT EXISTS User("
               "login varchar(20) not null,"
               "password varchar(20) not null,"
               "email varchar(20) not null,"
               "role varchar(20) not null,"
               "socket_id varchar(20),"
               "current_task_type INT not NULL default 0,"
               "current_task_payload TEXT,"
               "current_task_answer TEXT,"
               "task1_stat int not null,"
               "task2_stat int not null,"
               "task3_stat int NOT NULL,"
               "task4_stat int not NULL,"
               "task5_stat int not NULL)");
}

Database::~Database() {
    //отключить бд
    db.close();
}

Database* Database::getInstance() {
    if (!p_instance)
    {
        p_instance = new Database();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

bool Database::is_admin(int socket_descriptor)
{
    QSqlQuery query(db);
    query.prepare("SELECT 1 from User where socket_id = :socket_id and role = \'admin\'");
    query.bindValue(":socket_id", socket_descriptor);
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return false;
    }
    if (query.next()) {
        return true;
    }
    return false;
}

bool Database::is_connected(int socket_descriptor)
{
    QSqlQuery query(db);
    query.prepare("SELECT 1 from User where socket_id = :socket_id");
    query.bindValue(":socket_id", socket_descriptor);
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return false;
    }
    if (query.next()) {
        return true;
    }
    return false;
};

bool Database::is_auth_ok(QString login, QString password, int socket_descriptor)
{
    if (!is_connected(socket_descriptor)) {
        QSqlQuery query(db);
        query.prepare("SELECT 1 from User where login = :login and password = :password");
        query.bindValue(":login", login);
        query.bindValue(":password", password);
        if (!query.exec()) {
            qDebug() << query.lastError().text();
            return false;
        }
        if (!query.next()) {
            qDebug() << "Incorrect login/password!\r\n";
            return false;
        }

        query.prepare("SELECT 1 from User where login = :login and password = :password and socket_id is not null");
        query.bindValue(":login", login);
        query.bindValue(":password", password);
        if (!query.exec()) {
            qDebug() << query.lastError().text();
            return false;
        }
        if (query.next()) {
            qDebug() << "User already connected!\r\n";
            return false;
        }


        query.prepare("UPDATE User SET socket_id = :socket_id WHERE login = :login and password = :password");
        query.bindValue(":socket_id", socket_descriptor);
        query.bindValue(":login", login);
        query.bindValue(":password", password);
        if (!query.exec()) {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }
    return false;
};

bool Database::is_reg_ok(QString login, QString email, QString password, int socket_descriptor)
{
    if (!is_connected(socket_descriptor)) {
        QSqlQuery query(db);
        query.prepare("select * from User where login = :login or email = :email");
        query.bindValue(":login", login);
        query.bindValue(":email", email);
        if (!query.exec()) {
            qDebug() << query.lastError().text() + "\r\n";
            return false;
        }
        if (query.next()) {
            qDebug() << "This username/email already exists!\r\n";
            return false;
        }

        query.prepare("INSERT INTO User(login, email, password, socket_id, role, task1_stat, task2_stat, task3_stat, task4_stat, task5_stat)"
                      "VALUES (:login, :email, :password, :socket_id, \'user\', 0, 0, 0, 0, 0)");
        query.bindValue(":login", login);
        query.bindValue(":email", email);
        query.bindValue(":password", password);
        query.bindValue(":socket_id", socket_descriptor);
        if (!query.exec()) {
            qDebug() << query.lastError().text();
            return false;
        }
        return true;
    }
    return false;

};

bool Database::save_current_task(int socket_descriptor, const CurrentTask& task)
{
    QSqlQuery query(db);
    query.prepare("update User set "
                  "current_task_type = :type, "
                  "current_task_payload = :payload, "
                  "current_task_answer = :answer "
                  "where socket_id = :socket_id");
    query.bindValue(":type", task.type);
    query.bindValue(":payload", task.payload);
    query.bindValue(":answer", task.answer);
    query.bindValue(":socket_id", socket_descriptor);
    if (!query.exec()){
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
}

CurrentTask Database::get_current_task(int socket_descriptor)
{
    QSqlQuery query(db);
    query.prepare("SELECT current_task_type, current_task_payload, current_task_answer "
                  "from User where socket_id = :socket_id");
    query.bindValue(":socket_id", socket_descriptor);
    if (!query.exec()) {
        qDebug() << query.lastError().text();
    }
    if (!query.next()) {
        qDebug() << "User not found!";
        return CurrentTask();
    }
    CurrentTask task;
    task.type = query.value(0).toInt();
    task.payload = query.value(1).toString();
    task.answer = query.value(2).toString();
    return task;
}

bool Database::clear_current_task(int socket_descriptor)
{
    QSqlQuery query(db);
    query.prepare("update User set "
                  "current_task_type = 0,"
                  "current_task_payload = '',"
                  "current_task_answer = '' "
                  "where socket_id = :socket_id");
    query.bindValue(":socket_id", socket_descriptor);
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
};

bool Database::update_stat(int task_number, int socket_descriptor, bool is_correct)
{
    QString column;
    switch (task_number) {
    case 1: column = "task1_stat"; break;
    case 2: column = "task2_stat"; break;
    case 3: column = "task3_stat"; break;
    case 4: column = "task4_stat"; break;
    case 5: column = "task5_stat"; break;
    default:
        qDebug() << "Invalid task number!\r\n";
        return false;
    }

    int points = is_correct ? 1 : -2;

    QSqlQuery query(db);
    QString sql_request = QString("UPDATE User SET %1 = %1 + :points WHERE socket_id = :socket_id").arg(column);
    query.prepare(sql_request);
    query.bindValue(":points", points);
    query.bindValue(":socket_id", socket_descriptor);
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::drop_all_connections()
{
    QSqlQuery query(db);
    if (!query.exec("UPDATE User set socket_id = NULL")) {
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
};

bool Database::log_out(int socket_descriptor)
{
    QSqlQuery query(db);
    query.prepare("UPDATE User SET socket_id = NULL where socket_id = :socket_id");
    query.bindValue(":socket_id", socket_descriptor);
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
};
QString Database::get_current_stat(int socket_descriptor)
{
    QSqlQuery query(db);
    query.prepare("SELECT task1_stat, task2_stat, task3_stat, task4_stat, task5_stat from User where socket_id = :socket_id");
    query.bindValue(":socket_id", socket_descriptor);
    if (!query.exec()) {
        return query.lastError().text();
    }
    if (query.next()) {
        QSqlRecord rec = query.record();
        const int task1_stat_index = rec.indexOf("task1_stat");
        const int task2_stat_index = rec.indexOf("task2_stat");
        const int task3_stat_index = rec.indexOf("task3_stat");
        const int task4_stat_index = rec.indexOf("task4_stat");
        const int task5_stat_index = rec.indexOf("task5_stat");

        return query.value(task1_stat_index).toString() + "||" + query.value(task2_stat_index).toString()
               + "||" + query.value(task3_stat_index).toString() + "||" + query.value(task4_stat_index).toString() + "||" + query.value(task5_stat_index).toString() + "\r\n";
    }
    return "curr_stat_error\r\n";
};
QString Database::get_all_stat(int socket_descriptor)
{
    QSqlQuery query(db);
    QString result = "";
    if (is_admin(socket_descriptor)) {
        if (!query.exec("SELECT login, task1_stat, task2_stat, task3_stat, task4_stat, task5_stat from User")) {
            return query.lastError().text();
        }

        while (query.next()) {
            result += query.value(0).toString() + "||"
                      + query.value(1).toString() + "||"
                      + query.value(2).toString() + "||"
                      + query.value(3).toString() + "||"
                      + query.value(4).toString() + "||"
                      + query.value(5).toString() + "\r\n";
        }
        return result;
    }
    else {
        return "all_stat_access_denied\r\n";
    }
};
