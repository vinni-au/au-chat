#include "networkmessage.hpp"

NetworkMessage::NetworkMessage(boost::shared_ptr<Message> message,
                               uint32_t flags, ProtocolVersion version) :
    m_flags(flags), m_version(version.packed()), m_message(message)
{
    m_length = m_message->toJSON().size();
}

std::vector<uint8_t> NetworkMessage::toByteArray() {
    union {
        uint32_t uint32;
        uint8_t uints8[4];

    } _32to8;

    std::vector<uint8_t> result;
    result.push_back(m_message->type());

    _32to8.uint32 = m_length;
    std::for_each(_32to8.uints8, _32to8.uints8+4,
                  [&result](uint8_t& b){ result.push_back(b);});

    std::string msg = m_message->toJSON();
    std::for_each(msg.begin(), msg.end(),
                  [&result](char& ch){ result.push_back(ch);});

    _32to8.uint32 = m_flags;
    std::for_each(_32to8.uints8, _32to8.uints8+4,
                  [&result](uint8_t& b){ result.push_back(b);});

    result.push_back( uint8_t(m_version >> 8) );
    result.push_back( uint8_t(m_version | 0xFF) );

    return result;
}
