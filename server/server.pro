TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

include(../config.pri)

SOURCES += main.cpp


INCLUDEPATH += ../au-chat-core
LIBS += ../au-chat-core/libau-chat-core.a
