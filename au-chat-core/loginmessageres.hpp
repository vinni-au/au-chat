#ifndef LOGINMESSAGERES_HPP
#define LOGINMESSAGERES_HPP

#include "message.hpp"

class LoginMessageRes : public Message
{
public:

    enum Error {
        NOERROR = 0x0,
        WRONG_NICKNAME = 0x1
    };

    std::string toJSON();

private:
    LoginMessageRes(Error error);

    Error m_error;

    friend class MessageFactory;
};

#endif // LOGINMESSAGERES_HPP
