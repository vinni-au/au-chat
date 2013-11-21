#ifndef LISTUSERMESSAGEREQ_HPP
#define LISTUSERMESSAGEREQ_HPP

#include "message.hpp"

class ListUserMessageReq : public Message
{
public:

    std::string toJSON();

private:
    ListUserMessageReq();

    friend class MessageFactory;
};

#endif // LISTUSERMESSAGEREQ_HPP
