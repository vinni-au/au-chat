#include "listusermessagereq.hpp"

ListUserMessageReq::ListUserMessageReq()
{
    m_type = ListUserReq;
}

std::string ListUserMessageReq::toJSON() {
    json_spirit::Object object;
    object["type"] = m_type;
    return json_spirit::write_string( json_spirit::Value(object) );
}
