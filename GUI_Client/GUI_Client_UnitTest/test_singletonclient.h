#ifndef TEST_SINGLETONCLIENT_H
#define TEST_SINGLETONCLIENT_H

#include <QtTest/QtTest>
#include <QObject>

class TestSingletonClient : public QObject
{
    Q_OBJECT

private slots:
    void testGetInstance();
    void testSingletonPattern();
    void testSendMessage();
    void testEmptyMessage();
    void testMultipleMessages();
};

#endif // TEST_SINGLETONCLIENT_H
