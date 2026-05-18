QT -= gui
QT += network sql

CONFIG += c++20 console
CONFIG -= app_bundle

TARGET = tcpServer
TEMPLATE = app

SOURCES += \
    tcpserver.cpp \
    commandparser.cpp \
    commands.cpp \
    database.cpp \
    tasks.cpp \
    main.cpp

HEADERS += \
    tcpserver.h \
    commandparser.h \
    commands.h \
    database.h \
    tasks.h
