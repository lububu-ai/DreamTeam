#ifndef TEST_CLIENTFUNCS_H
#define TEST_CLIENTFUNCS_H

#include <QtTest/QtTest>
#include <QObject>

class TestClientFuncs : public QObject
{
    Q_OBJECT

private slots:
    void testExtractArgsNormal();
    void testAuthMessageFormat();
    void testRegMessageFormat();
    void testGetTaskMessageFormat();
    void testSendAnswerMessageFormat();
    void testAuthSuccess();
    void testAuthFail();
    void testSendAnswerCorrect();
    void testSendAnswerIncorrect();
};

#endif // TEST_CLIENTFUNCS_H
