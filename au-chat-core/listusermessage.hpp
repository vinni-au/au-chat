#ifndef LISTUSERMESSAGE_HPP
#define LISTUSERMESSAGE_HPP

#include "message.hpp"
#include <list>

class ListUserMessage : public Message
{
public:
    std::string toJSON();

private:
    ListUserMessage(uint16_t count, std::list<std::string> users);

    uint16_t m_count;
    std::list<std::string> m_users;

    friend class MessageFactory;
};

#endif // LISTUSERMESSAGE_HPP
