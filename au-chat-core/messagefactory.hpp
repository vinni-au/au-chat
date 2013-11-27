#ifndef MESSAGEFACTORY_HPP
#define MESSAGEFACTORY_HPP

#include "loginmessage.hpp"
#include "loginmessageres.hpp"
#include "fetchmessage.hpp"
#include "textmessage.hpp"
#include "sendmessage.hpp"
#include "logoutmessagereq.hpp"
#include "listusermessagereq.hpp"
#include "listusermessage.hpp"
#include <boost/shared_ptr.hpp>

class MessageFactory
{
public:
    static
    boost::shared_ptr<Message> fromJSON(std::string json);

    static
    boost::shared_ptr<LoginMessage> createLoginMessage(std::string login);

    static
    boost::shared_ptr<LoginMessageRes>
    createLoginMessageRes(LoginMessageRes::Error error);

    static
    boost::shared_ptr<FetchMessage> createFetchMessage(uint32_t lastID);

    static
    boost::shared_ptr<TextMessage>
    createTextMessage(uint32_t id, std::string nickname, std::string text);

    static
    boost::shared_ptr<SendMessage> createSendMessage(std::string text);

    static
    boost::shared_ptr<LogoutMessageReq> createLogoutMessageReq();

    static
    boost::shared_ptr<ListUserMessageReq> createListUserMessageReq();

    static
    boost::shared_ptr<ListUserMessage>
    createListUserMessage(uint16_t count, std::list<std::string> users);
};

#endif // MESSAGEFACTORY_HPP
