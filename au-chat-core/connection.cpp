#include "connection.hpp"

Connection::Connection(boost::asio::io_service &ioservice,
                       ProtocolVersion version)
    : m_socket(ioservice)
    , m_version(version)
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

void Connection::sendMessage(boost::shared_ptr<NetworkMessage> message) {

}
