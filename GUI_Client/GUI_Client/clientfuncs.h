#ifndef CLIENTFUNCS_H
#define CLIENTFUNCS_H
#include<QString>
#include <QStringList>
#include <QVector>

/**
 * @file clientfuncs.h
 * @brief Объявление изолированных глобальных функций для отправки запросов на сервер и обработки ответов.
 */

/**
 * @brief Авторизация пользователя в системе.
 * @param log Логин пользователя.
 * @param pw Пароль пользователя.
 * @param[out] role Переменная для сохранения роли («user» или «admin»), возвращенной сервером.
 * @return true, если авторизация успешна, иначе false.
 */
bool auth(QString log, QString pw, QString& role);
/**
 * @brief Регистрация нового пользователя в системе.
 * @param log Логин пользователя.
 * @param email Электронная почта.
 * @param pw Пароль пользователя.
 * @param[out] role Ссылка для записи полученной роли пользователя.
 * @return true, если регистрация завершилась успехом, иначе false.
 */
bool reg(QString log, QString email, QString pw, QString& role);
/**
 * @brief Запрос payload-строки параметров математической задачи у сервера.
 * @param num Строковый номер типа задачи (от «1» до «5»).
 * @return Строка с параметрами задачи или сообщение об ошибке.
 */
QString getTask(QString num);
/**
 * @brief Получение персональной статистики текущего авторизованного пользователя.
 * @return Строка со статистикой по выполненным задачам, разделенная символами "||".
 */
QString getStats();
/**
 * @brief Отправка ответа на задачу для проверки на стороне сервера.
 * @param num Номер проверяемой задачи.
 * @param answer Строка с ответом, введённым пользователем.
 * @return true, если сервер подтвердил правильность ответа, иначе false.
 */
bool sendAnswer(QString num, QString answer);
/**
 * @brief Вспомогательная функция для парсинга аргументов из сырого ответа сервера.
 * @param servAns Ответ, пришедший от сервера.
 * @param[out] args Вектор, в который будут записаны извлеченные параметры.
 */
void extractArgs(QString servAns, QVector <QString> &args);
/**
 * @brief Запрос статистики по всем пользователям (доступно только администратору).
 * @return Сводный текстовый массив данных всех учетных записей.
 */
QString getAllStats();
/**
 * @brief Запрос топ-10 пользователей по сумме набранных баллов (доступно только администратору).
 * @return Текстовая таблица лидеров.
 */
QString getTop10Stats();
/**
 * @brief Удаление пользователя из базы данных по его логину (доступно только администратору).
 * @param login Логин удаляемого пользователя.
 * @return true, если удаление прошло успешно, иначе false.
 */
bool delete_user(QString login);
/**
 * @brief Форматирование сырых данных от сервера в удобочитаемый вид HTML-таблицы или текста.
 * @param serverData Ответ сервера, разделенный маркерами "||".
 * @return Отформатированная строка для вывода в интерфейс.
 */
QString getStatsTable(QString serverData);

#endif // CLIENTFUNCS_H
