#ifndef TEXTMESSAGE_HPP
#define TEXTMESSAGE_HPP

#include "message.hpp"
#include <QSqlQuery>

class TextMessage : public Message
{
public:

    std::string toJSON();

    boost::shared_ptr<QSqlQuery> insertQuery();
    boost::shared_ptr<QSqlQuery> selectQuery(uint32_t lastid);

private:
    uint32_t m_id;
    std::string m_nickname;
    std::string m_text;

    TextMessage(uint32_t id, std::string nickname, std::string text);

    friend class MessageFactory;
};

#endif // TEXTMESSAGE_HPP
