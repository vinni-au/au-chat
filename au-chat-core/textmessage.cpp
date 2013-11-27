#include "textmessage.hpp"

TextMessage::TextMessage(uint32_t id, std::string nickname, std::string text) :
    m_id(id),
    m_nickname(nickname),
    m_text(text)
{
    m_type = Text;
}

std::string TextMessage::toJSON() {
    json_spirit::Object object;
    object["type"] = m_type;
    object["id"] = m_id;
    object["nickname"] = m_nickname;
    object["text"] = m_text;
    return json_spirit::write_string( json_spirit::Value(object) );
}
