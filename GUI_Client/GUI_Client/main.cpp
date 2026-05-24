#include "managerform.h"
#include "singletonclient.h"

#include <QApplication>
/**
 * @file main.cpp
 * @brief Точка входа в клиентское Qt-приложение.
 */

/**
 * @brief Главная функция.
 * * Инициализирует менеджер графических окон `ManagerForm` и производит
 * стартовое "холостое" обращение к TCP-серверу для проверки доступности сетевого соединения.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код завершения выполнения приложения Qt.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ManagerForm s;

    QString conec = SingletonClient::getInstance()->send_msg_to_server(QString::fromStdString(""));

    return a.exec();
}
