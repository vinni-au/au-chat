QT       -= core gui

TARGET = au-chat-core
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += ../json-spirit/include
LIBS += ../json-spirit/build/libjson_spirit.a

SOURCES += message.cpp \
    messagefactory.cpp \
    loginmessage.cpp \
    loginmessageres.cpp \
    fetchmessage.cpp

HEADERS += message.hpp \
    messagefactory.hpp \
    loginmessage.hpp \
    loginmessageres.hpp \
    fetchmessage.hpp

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
