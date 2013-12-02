#include "textmessage.hpp"
#include <QVariant>

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

boost::shared_ptr<QSqlQuery> TextMessage::insertQuery() {
    boost::shared_ptr<QSqlQuery> result( new QSqlQuery );
    result->prepare("INSERT INTO messages(id, nickname, text)"
                    "VALUES (:id, :nickname, :text");
    result->bindValue(":id", m_id);
    result->bindValue(":nickname", m_nickname.c_str());
    result->bindValue(":text", m_text.c_str());
    return result;
}

boost::shared_ptr<QSqlQuery> TextMessage::selectQuery(uint32_t lastid) {
    boost::shared_ptr<QSqlQuery> result( new QSqlQuery );
    result->prepare("SELECT id, nickname, text"
                    "FROM messages"
                    "WHERE id > :lastid");
    result->bindValue(":lastid", lastid);
    return result;
}
