#-------------------------------------------------
#
# Project created by QtCreator 2020-03-06T16:39:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GOL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    board.cpp \
    boardwidget.cpp

HEADERS  += mainwindow.h \
    board.h \
    boardwidget.h

FORMS    += mainwindow.ui
