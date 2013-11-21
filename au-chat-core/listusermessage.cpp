#include "listusermessage.hpp"

ListUserMessage::ListUserMessage(uint16_t count, std::list<std::string> users) :
    m_count(count),
    m_users(users)
{
    m_type = ListUser;
}


std::string ListUserMessage::toJSON() {
    return "";
}
