QT       -= core gui

TARGET = au-chat-core
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../json-spirit/include
LIBS += ../json-spirit/build/libjson_spirit.a

SOURCES += message.cpp

HEADERS += message.hpp

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
