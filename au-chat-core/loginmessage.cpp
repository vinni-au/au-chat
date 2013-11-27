#include "loginmessage.hpp"

LoginMessage::LoginMessage(std::string login) :
    m_login(login)
{
    m_type = Login;
}

std::string LoginMessage::toJSON() {
    json_spirit::Object object;
    object["type"] = m_type;
    object["login"] = m_login;
    return json_spirit::write_string( json_spirit::Value(object) );
}
