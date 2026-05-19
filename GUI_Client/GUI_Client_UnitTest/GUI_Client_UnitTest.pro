QT += core network testlib
QT -= gui widgets

CONFIG += c++17 console
CONFIG -= app_bundle

INCLUDEPATH += ../GUI_Client
DEPENDPATH += ../GUI_Client

SOURCES += \
    ../GUI_Client/clientfuncs.cpp \
    ../GUI_Client/singletonclient.cpp \
    test_main.cpp \
    test_clientfuncs.cpp \
    test_singletonclient.cpp

HEADERS += \
    ../GUI_Client/clientfuncs.h \
    ../GUI_Client/singletonclient.h \
    test_clientfuncs.h \
    test_singletonclient.h

win32: LIBS += -lws2_32

DEFINES += UNIT_TEST
