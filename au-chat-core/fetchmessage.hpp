#ifndef FETCHMESSAGE_HPP
#define FETCHMESSAGE_HPP

#include "message.hpp"
#include <cstdint>

class FetchMessage : public Message
{
public:

    std::string toJSON();

private:
    FetchMessage(uint32_t lastID);

    uint32_t m_lastID;
};

#endif // FETCHMESSAGE_HPP
