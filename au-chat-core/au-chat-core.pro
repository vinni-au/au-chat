QT       += core sql
QT -= gui

TARGET = au-chat-core
TEMPLATE = lib
CONFIG += staticlib

include(../config.pri)

INCLUDEPATH += ../json-spirit/include

SOURCES += message.cpp \
    messagefactory.cpp \
    loginmessage.cpp \
    loginmessageres.cpp \
    fetchmessage.cpp \
    textmessage.cpp \
    sendmessage.cpp \
    logoutmessagereq.cpp \
    listusermessagereq.cpp \
    listusermessage.cpp \
    networkmessage.cpp \
    connection.cpp

HEADERS += message.hpp \
    messagefactory.hpp \
    loginmessage.hpp \
    loginmessageres.hpp \
    fetchmessage.hpp \
    textmessage.hpp \
    sendmessage.hpp \
    logoutmessagereq.hpp \
    listusermessagereq.hpp \
    listusermessage.hpp \
    networkmessage.hpp \
    connection.hpp

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
