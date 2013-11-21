#include "loginmessage.hpp"

LoginMessage::LoginMessage(std::string login) :
    m_login(login)
{
    m_type = Login;
}

std::string LoginMessage::toJSON() {
    return "";
}
