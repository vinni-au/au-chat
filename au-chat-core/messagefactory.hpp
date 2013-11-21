#ifndef MESSAGEFACTORY_HPP
#define MESSAGEFACTORY_HPP

#include "message.hpp"
#include "loginmessage.hpp"
#include "loginmessageres.hpp"
#include <boost/shared_ptr.hpp>

class MessageFactory
{
public:
    boost::shared_ptr<Message> fromJSON(std::string json);

    boost::shared_ptr<LoginMessage> createLoginMessage(std::string login);

    boost::shared_ptr<LoginMessageRes>
    createLoginMessageRes(LoginMessageRes::Error error);
};

#endif // MESSAGEFACTORY_HPP
