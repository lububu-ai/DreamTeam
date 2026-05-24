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
/**
 * @file database.h
 * @brief Объявление класса для работы с базой данных SQLite на основе паттерна Singleton.
 */
class Database;
/**
 * @class DatabaseDestroyer
 * @brief Вспомогательный класс для корректного освобождения памяти Singleton-экземпляра Database.
 */
class DatabaseDestroyer
{
	private:
        Database * p_instance; ///< Указатель на единственный экземпляр Database.
	public:
        /**
        * @brief Деструктор. Удаляет выделенный объект Database.
        */
        ~DatabaseDestroyer();
        /**
        * @brief Инициализация деструктора ссылкой на экземпляр.
        * @param p Указатель на созданный объект Database.
        */
        void initialize(Database * p);
};

/**
 * @class Database
 * @brief Обертка над базой данных SQLite для управления пользователями, сессиями и статистикой.
 * * Реализует паттерн Singleton для обеспечения единой точки доступа к ресурсу БД.
 */
class Database
{
	private:
        static Database * p_instance; ///< Единственный экземпляр класса Database.
        static DatabaseDestroyer destroyer; ///< Объект-разрушитель для очистки памяти.
        QSqlDatabase db; ///< Объект соединения с SQLite.
	protected:
        /**
        * @brief Защищенный конструктор. Выполняет открытие БД и создание таблиц, если они отсутствуют.
        */
        Database();
        Database(const Database&) = delete;
        Database& operator = (Database &) = delete;
        /**
        * @brief Защищенный деструктор. Закрывает соединение с БД.
        */
        ~Database();
        friend class DatabaseDestroyer;
	public:
        /**
        * @brief Возвращает указатель на единственный экземпляр класса.
        * @return Database* Указатель на объект Database.
        */
        static Database* getInstance();
        /**
        * @brief Удаляет пользователя по его логину, проверяя права администратора у текущего сокета.
        */
        bool delete_user(QString, int);
        /**
        * @brief Тестовое удаление пользователя (без проверки прав администратора).
        */
        bool delete_user_test(QString);
        /**
        * @brief Проверяет, является ли пользователь с данным сокетом администратором.
        */
        bool is_admin(int);
        /**
        * @brief Проверяет, привязан ли сокет к какому-либо авторизованному пользователю.
        */
        bool is_connected(int);
        /**
        * @brief Авторизует пользователя, проверяя логин/пароль и привязывая socket_descriptor.
        */
        bool is_auth_ok(QString, QString, int);
        /**
        * @brief Регистрирует нового пользователя с ролью 'user' и начальной нулевой статистикой.
        */
        bool is_reg_ok(QString, QString, QString, int);
        /**
        * @brief Отвязывает сокет от пользователя (устанавливает socket_id в NULL).
        */
        bool log_out(int);
        /**
        * @brief Сохраняет текущую выданную задачу в профиль пользователя.
        */
        bool save_current_task(int, const CurrentTask&);
        /**
        * @brief Возвращает структуру текущей задачи пользователя.
        */
        CurrentTask get_current_task(int);
        /**
        * @brief Очищает поля текущей задачи у пользователя (сбрасывает в состояние по умолчанию).
        */
        bool clear_current_task(int);
        /**
        * @brief Обновляет статистику (баллы) по конкретной задаче (+1 за верный ответ, -2 за неверный).
        */
        bool update_stat(int, int, bool);
        /**
        * @brief Сбрасывает все активные сокеты в базе данных (используется при старте сервера).
        */
        bool drop_all_connections();
        /**
        * @brief Формирует строку персональной статистики пользователя.
        */
        QString get_current_stat(int);
        /**
        * @brief Формирует список статистики первых 15 пользователей.
        */
        QString get_all_stat(int);
        /**
        * @brief Формирует список топ-10 пользователей, отсортированный по убыванию баллов.
        */
        QString get_top_10_stat(int);
};

#endif // DATABASE_H
