#include "listusermessagereq.hpp"

ListUserMessageReq::ListUserMessageReq()
{
    m_type = ListUserReq;
}

std::string ListUserMessageReq::toJSON() {
    return "";
}
