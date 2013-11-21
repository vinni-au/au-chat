#include "loginmessageres.hpp"

LoginMessageRes::LoginMessageRes(Error error)
    : m_error(error)
{
    m_type = LoginRes;
}

std::string LoginMessageRes::toJSON() {
    return "";
}
