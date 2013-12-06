TEMPLATE = app
CONFIG += console qt
CONFIG -= app_bundle
QT += core sql
QT -= gui

include(../config.pri)

SOURCES += main.cpp

INCLUDEPATH += ../au-chat-core ../json-spirit/include
LIBS += ../au-chat-core/libau-chat-core.a -lboost_system -lboost_thread
