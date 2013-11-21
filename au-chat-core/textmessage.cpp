#include "textmessage.hpp"

TextMessage::TextMessage(uint32_t id, std::string nickname, std::string text) :
    m_id(id),
    m_nickname(nickname),
    m_text(text)
{
    m_type = Text;
}

std::string TextMessage::toJSON() {
    return "";
}
