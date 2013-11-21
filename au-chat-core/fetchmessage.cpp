#include "fetchmessage.hpp"

FetchMessage::FetchMessage(uint32_t lastID) :
    m_lastID(lastID)
{
    m_type = Fetch;
}

std::string FetchMessage::toJSON() {
    return "";
}
