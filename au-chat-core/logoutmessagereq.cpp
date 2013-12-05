#include "logoutmessagereq.hpp"

LogoutMessageReq::LogoutMessageReq()
{
    m_type = LogoutReq;
}

std::string LogoutMessageReq::toJSON() {
    return "";
}
