#-------------------------------------------------
#
# Project created by QtCreator 2015-09-22T14:08:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatSec
TEMPLATE = app


SOURCES += main.cpp\
        mainchatwindow.cpp \
    login.cpp \
    logindialogue.cpp \
    user.cpp \
    channel.cpp \
    channelselect.cpp \
    crypter.cpp

HEADERS  += mainchatwindow.h \
    user.h \
    login.h \
    logindialogue.h \
    channel.h \
    channelselect.h \
    crypter.h

FORMS    += mainchatwindow.ui \
    login.ui \
    logindialogue.ui \
    channelselect.ui




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../OpenSSL-Win64/lib/VC/ -llibeay32M
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../OpenSSL-Win64/lib/VC/ -llibeay32Md
else:unix: LIBS += -L$$PWD/../../../../OpenSSL-Win64/lib/VC/ -llibeay32M

INCLUDEPATH += $$PWD/../../../../OpenSSL-Win64/lib/VC
DEPENDPATH += $$PWD/../../../../OpenSSL-Win64/lib/VC

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../OpenSSL-Win64/lib/VC/ -lssleay32M
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../OpenSSL-Win64/lib/VC/ -lssleay32Md
else:unix: LIBS += -L$$PWD/../../../../OpenSSL-Win64/lib/VC/ -lssleay32M

INCLUDEPATH += $$PWD/../../../../OpenSSL-Win64/lib/VC
DEPENDPATH += $$PWD/../../../../OpenSSL-Win64/lib/VC
