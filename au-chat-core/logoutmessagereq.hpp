#ifndef LOGOUTMESSAGEREQ_HPP
#define LOGOUTMESSAGEREQ_HPP

#include "message.hpp"

class LogoutMessageReq : public Message
{
public:
    std::string toJSON();

private:
    LogoutMessageReq();

    friend class MessageFactory;
};

#endif // LOGOUTMESSAGEREQ_HPP
