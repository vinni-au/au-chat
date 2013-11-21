TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
    au-chat-core \
    server \
    client

server.depends = au-chat-core
client.depends = au-chat-core
