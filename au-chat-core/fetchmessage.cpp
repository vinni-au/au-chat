#include "fetchmessage.hpp"

#include <json_spirit/json_spirit.h>

FetchMessage::FetchMessage(uint32_t lastID) :
    m_lastID(lastID)
{
    m_type = Fetch;
}

std::string FetchMessage::toJSON() {
    json_spirit::Object object;
    object["type"] = m_type;
    object["lastid"] = m_lastID;
    return json_spirit::write(object);
}
