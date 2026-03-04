#include <Qstring>
#include <QStringList>


void registration(QString name, QString password); // регистрация
void authorization(QString name, QString password); // авторизация
void unlog(); // выход из аккаунта пользователя
void check(double a, double b, int k); // главная функция проекта
void exit_from_connection(); // закрытие соединения
void information(); // информация о возможностях
QString parsing(QString str); // парсинг полученного сообщения

