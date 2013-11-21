#ifndef SENDMESSAGE_HPP
#define SENDMESSAGE_HPP

#include "message.hpp"

class SendMessage : public Message
{
public:

    std::string toJSON();

private:
    SendMessage(std::string text);

    std::string m_text;

    friend class MessageFactory;
};

#endif // SENDMESSAGE_HPP
