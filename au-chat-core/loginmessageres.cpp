#include "loginmessageres.hpp"

LoginMessageRes::LoginMessageRes(Error error)
    : m_error(error)
{
    m_type = LoginRes;
}

std::string LoginMessageRes::toJSON() {
    json_spirit::Object object;
    object["error"] = m_error;
    return json_spirit::write_string( json_spirit::Value(object) );
}
