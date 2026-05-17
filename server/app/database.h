#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>

#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QString>

#include "tasks.h"

class Database;

class DatabaseDestroyer
{
	private:
        Database * p_instance;
	public:
        ~DatabaseDestroyer();
        void initialize(Database * p);
};


class Database
{
	private:
        static Database * p_instance;
        static DatabaseDestroyer destroyer;
        QSqlDatabase db;
	protected:
        Database();
        Database(const Database&) = delete;
        Database& operator = (Database &) = delete;
        ~Database();
        friend class DatabaseDestroyer;
	public:
        static Database* getInstance();
        bool delete_user(QString login);
        bool is_admin(int);
        bool is_connected(int);
        bool is_auth_ok(QString, QString, int);
        bool is_reg_ok(QString, QString, QString, int);
        bool log_out(int);
        bool save_current_task(int, const CurrentTask&);
        CurrentTask get_current_task(int);
        bool clear_current_task(int);
        bool update_stat(int, int, bool);
        bool drop_all_connections();
        QString get_current_stat(int);
        QString get_all_stat(int);
};

#endif // DATABASE_H
