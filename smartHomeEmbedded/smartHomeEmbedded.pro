TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT +=network

SOURCES += main.cpp \
    communicationlibrary.cpp \
    sensorsmanager.cpp \
    messagetranslator.cpp \
    livingroommanager.cpp

HEADERS += \
    communicationlibrary.h \
    communicationmessagesdefinition.h \
    sensorsmanager.h \
    messagetranslator.h \
    livingroommanager.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/ -lwiringPi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/ -lwiringPi
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lwiringPi

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/ -lwiringPiDev
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/ -lwiringPiDev
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lwiringPiDev

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

LIBS += -L$$PWD/../../../../../usr/local/lib/ -lcrypt
