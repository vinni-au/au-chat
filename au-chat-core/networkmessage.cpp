#include "networkmessage.hpp"

NetworkMessage::NetworkMessage(boost::shared_ptr<Message> message,
                               uint32_t flags, ProtocolVersion version) :
    m_message(message),
    m_header(message->type(), message->size(), flags, version)
{
}

std::vector<uint8_t> NetworkMessage::toByteArray() {
    std::vector<uint8_t> result;

    std::vector<uint8_t> header = m_header.toByteArray();
    std::copy(header.begin(), header.end(), std::back_inserter(result));

    std::string json = m_message->json();
    std::copy(json.begin(), json.end(), std::back_inserter(result));

    return result;
}
