#include "sendmessage.hpp"

SendMessage::SendMessage(std::string text) :
    m_text(text)
{
    m_type = Send;
}

std::string SendMessage::toJSON() {
    json_spirit::Object object;
    object["type"] = m_type;
    object["text"] = m_text;
    return json_spirit::write_string( json_spirit::Value(object) );
}
