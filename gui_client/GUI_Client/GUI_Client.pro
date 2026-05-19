QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets \
    network sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminform.cpp \
    clientfuncs.cpp \
    main.cpp \
    authregform.cpp \
    mainform.cpp \
    managerform.cpp \
    singletonclient.cpp

HEADERS += \
    adminform.h \
    authregform.h \
    clientfuncs.h \
    mainform.h \
    managerform.h \
    singletonclient.h

FORMS += \
    adminform.ui \
    authregform.ui \
    mainform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
