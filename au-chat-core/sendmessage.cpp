#include "sendmessage.hpp"

SendMessage::SendMessage(std::string text) :
    m_text(text)
{
    m_type = Send;
}

std::string SendMessage::toJSON() {
    return "";
}
