#-------------------------------------------------
#
# Project created by QtCreator 2017-08-18T20:44:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = loginWindow
TEMPLATE = app
CONFIG +=C++11
QT +=network

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    mvccontroller.cpp \
    mainScreenScenario.cpp \
    livingroomscreen.cpp \
    mainscreenwindow.cpp

HEADERS  += mainwindow.h \
    mvccontroller.h \
    catchheader.h \
    livingroomscreen.h \
    mainscreenwindow.h

FORMS    += \
    loginwindow.ui \
    livingroomscreen.ui \
    mainscreenwindow.ui

RESOURCES += \
    resources.qrc




win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../communicationLibrary/release/ -lcommunicationLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../communicationLibrary/debug/ -lcommunicationLibrary
else:unix: LIBS += -L$$OUT_PWD/../communicationLibrary/ -lcommunicationLibrary

INCLUDEPATH += $$PWD/../communicationLibrary
DEPENDPATH += $$PWD/../communicationLibrary

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../communicationLibrary/release/libcommunicationLibrary.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../communicationLibrary/debug/libcommunicationLibrary.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../communicationLibrary/release/communicationLibrary.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../communicationLibrary/debug/communicationLibrary.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../communicationLibrary/libcommunicationLibrary.a
