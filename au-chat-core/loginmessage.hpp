#ifndef LOGINMESSAGE_HPP
#define LOGINMESSAGE_HPP

#include "message.hpp"

class LoginMessage : public Message
{
public:
    std::string toJSON();

private:
    LoginMessage(std::string login);

    std::string m_login;

    friend class MessageFactory;
};

#endif // LOGINMESSAGE_HPP
