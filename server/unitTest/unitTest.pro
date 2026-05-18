QT += testlib core sql
CONFIG += console testcase c++20
CONFIG -= app_bundle

TARGET = unitTest
TEMPLATE = app

SOURCES += \
    ../app/commandparser.cpp \
    ../app/commands.cpp \
    ../app/tasks.cpp \
    ../app/database.cpp \
    main_test.cpp \
    test_commandparser.cpp \
    test_database.cpp

HEADERS += \
    ../app/commandparser.h \
    ../app/commands.h \
    ../app/tasks.h \
    ../app/database.h \
    test_commandparser.h \
    test_database.h
