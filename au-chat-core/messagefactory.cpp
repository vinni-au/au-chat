#include "messagefactory.hpp"

boost::shared_ptr<Message> MessageFactory::fromJSON(std::string ) {
    return boost::shared_ptr<Message>();
}

boost::shared_ptr<LoginMessage>
MessageFactory::createLoginMessage(std::string login) {
    return boost::shared_ptr<LoginMessage>(
                    new LoginMessage( login )
                );
}

boost::shared_ptr<LoginMessageRes>
MessageFactory::createLoginMessageRes(LoginMessageRes::Error error) {
    return boost::shared_ptr<LoginMessageRes> (
                    new LoginMessageRes( error )
                );
}

boost::shared_ptr<FetchMessage>
MessageFactory::createFetchMessage(uint32_t lastID) {
    return boost::shared_ptr<FetchMessage> (
                    new FetchMessage( lastID )
                );
}

boost::shared_ptr<TextMessage>
MessageFactory::createTextMessage(uint32_t id, std::string nickname, std::string text) {
    return boost::shared_ptr<TextMessage> (
                    new TextMessage(id, nickname, text)
                );
}

boost::shared_ptr<SendMessage>
MessageFactory::createSendMessage(std::string text) {
    return boost::shared_ptr<SendMessage> (
                    new SendMessage(text)
                );
}

boost::shared_ptr<LogoutMessageReq>
MessageFactory::createLogoutMessageReq() {
    return boost::shared_ptr<LogoutMessageReq> (
                    new LogoutMessageReq
                );
}

boost::shared_ptr<ListUserMessageReq>
MessageFactory::createListUserMessageReq() {
    return boost::shared_ptr<ListUserMessageReq>(
                    new ListUserMessageReq
                );
}

boost::shared_ptr<ListUserMessage>
MessageFactory::createListUserMessage(uint16_t count, std::list<std::string> users) {
    return boost::shared_ptr<ListUserMessage>(
                    new ListUserMessage(count, users)
                );
}
