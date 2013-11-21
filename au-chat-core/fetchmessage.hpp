#ifndef FETCHMESSAGE_HPP
#define FETCHMESSAGE_HPP

#include "message.hpp"

class FetchMessage : public Message
{
public:

    std::string toJSON();

private:
    FetchMessage(uint32_t lastID);

    uint32_t m_lastID;

    friend class MessageFactory;
};

#endif // FETCHMESSAGE_HPP
