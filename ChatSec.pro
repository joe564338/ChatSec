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
    login.cpp

HEADERS  += mainchatwindow.h \
    user.h \
    login.h

FORMS    += mainchatwindow.ui \
    login.ui
