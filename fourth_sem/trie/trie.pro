#-------------------------------------------------
#
# Project created by QtCreator 2014-02-17T18:50:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trie
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tnode.cpp \
    ttrietree.cpp

HEADERS  += mainwindow.h \
    tnode.h \
    ttrietree.h

FORMS    += mainwindow.ui
