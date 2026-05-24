#include <QCoreApplication>
#include "tcpserver.h"

/**
 * @file main.cpp
 * @brief Точка входа в серверное приложение.
 */

/**
 * @brief Главная функция программы.
 * @details Инициализирует генератор случайных чисел, создает главное событийно-ориентированное
 * приложение Qt и запускает экземпляр TCP-сервера.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код возврата приложения.
 */
int main(int argc, char *argv[])
{
    srand(time(nullptr));
    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    return a.exec();
}
