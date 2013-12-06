#include "connection.hpp"

Connection::Connection(boost::asio::io_service &ioservice,
                       ProtocolVersion version, uint32_t flags)
    : m_socket(ioservice)
    , m_version(version)
    , m_flags(flags)
{
}

void Connection::start() {
#ifdef DEBUG_MODE
    std::cout << "starting connection" << std::endl;
#endif

    boost::asio::async_read(m_socket,
                            boost::asio::buffer(m_data, NetworkMessage::Header::SIZE),
                            boost::bind(&Connection::handleReadHeader, this,
                                        boost::asio::placeholders::error));

}

void Connection::handleReadHeader(const boost::system::error_code &err) {
#ifdef DEBUG_MODE
    std::cout << "Connection::handleReadHeader" << std::endl;

    for (size_t i = 0; i < NetworkMessage::Header::SIZE; ++i) {
        std::cout << int(m_data[i]) << " ";
    }
    std::cout << std::endl;

#endif


}

void Connection::connect(tcp::endpoint& ep) {
    m_socket.connect(ep);
}

void Connection::sendMessage(boost::shared_ptr<Message> message) {
#ifdef DEBUG_MODE
    std::cout << "sending message" << std::endl;
#endif

    NetworkMessage msg(message, m_flags, m_version);
    std::vector<uint8_t> bytes = msg.toByteArray();
    m_socket.write_some(boost::asio::buffer(bytes, bytes.size()));
}
