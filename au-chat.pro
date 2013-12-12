TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
    au-chat-core \
    server \
    client \
    test

server.depends = au-chat-core
client.depends = au-chat-core
test.depends   = au-chat-core
