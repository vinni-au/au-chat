#include "listusermessage.hpp"

ListUserMessage::ListUserMessage(uint16_t count, std::list<std::string> users) :
    m_count(count),
    m_users(users)
{
    m_type = ListUser;
}


std::string ListUserMessage::toJSON() {
    json_spirit::Object object;
    json_spirit::Array users;
    object["type"] = m_type;
    object["usercount"] = m_count;
    for (const std::string & user : m_users) {
        users.push_back( json_spirit::Value( user ));
    }
    object["users"] = users;
    return json_spirit::write_string( json_spirit::Value(object) );
}
