QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app
INCLUDEPATH += ../au-chat-core
LIBS += ../au-chat-core/libau-chat-core.a


SOURCES += main.cpp\
        clientwindow.cpp

HEADERS  += clientwindow.hpp

FORMS    += clientwindow.ui
