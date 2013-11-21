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
