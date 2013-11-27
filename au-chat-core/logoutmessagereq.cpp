#include "logoutmessagereq.hpp"

LogoutMessageReq::LogoutMessageReq()
{
    m_type = LogoutReq;
}

std::string LogoutMessageReq::toJSON() {
    json_spirit::Object object;
    object["type"] = m_type;
    return json_spirit::write_string( json_spirit::Value(object) );
}
