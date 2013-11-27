TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += ../au-chat-core ../json-spirit/include
LIBS += ../au-chat-core/libau-chat-core.a -lboost_system

QMAKE_CXXFLAGS += -std=c++11
