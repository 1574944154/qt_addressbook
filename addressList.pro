QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addpersondialog.cpp \
    adduserdialog.cpp \
    adminwindow.cpp \
    department.cpp \
    departmentmapper.cpp \
    departmentservice.cpp \
    loginwindow.cpp \
    main.cpp \
    person.cpp \
    personmapper.cpp \
    personservice.cpp \
    user.cpp \
    usermapper.cpp \
    userservice.cpp \
    userwindow.cpp

HEADERS += \
    addpersondialog.h \
    adduserdialog.h \
    adminwindow.h \
    department.h \
    departmentmapper.h \
    departmentservice.h \
    loginwindow.h \
    person.h \
    personmapper.h \
    personservice.h \
    user.h \
    usermapper.h \
    userservice.h \
    userwindow.h

FORMS += \
    addpersondialog.ui \
    adduserdialog.ui \
    adminwindow.ui \
    loginwindow.ui \
    userwindow.ui

TRANSLATIONS += \
    addressList_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
