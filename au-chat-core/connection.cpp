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

//    m_socket.async_read_some(boost::asio::buffer(m_data, NetworkMessage::Header::SIZE),
//                             boost::bind(&Connection::handleReadHeader, this,
//                                         boost::asio::placeholders::error));

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

    std::vector<uint8_t> bytes;
    std::copy(m_data, m_data + NetworkMessage::Header::SIZE, std::back_inserter(bytes));

    NetworkMessage::Header header = NetworkMessage::Header::fromByteArray(bytes);
//    boost::asio::async_read(m_socket, boost::asio::buffer(m_data, header.length),
//                            boost::bind(&Connection::handleReadBody,
//                                        this, header,
//                                        boost::asio::placeholders::error()));
    boost::asio::read(m_socket, boost::asio::buffer(m_data, header.length));

#ifdef DEBUG_MODE
    std::cout << "reading body" << std::endl;

    for (int i = 0; i < header.length; ++i)
        std::cout << int(m_data[i]) << " ";

    std::cout << std::endl;
#endif

}

void Connection::handleReadBody(NetworkMessage::Header header,
                                const boost::system::error_code &err)
{
#ifdef DEBUG_MODE
    std::cout << "Connection::handleReadBody" << std::endl;

    for (int i = 0; i < header.length; ++i)
        std::cout << int(m_data[i]) << " ";

    std::cout << std::endl;
#endif

//    start();
}

void Connection::connect(tcp::endpoint& ep) {
    m_socket.connect(ep);
//    start();
}

void Connection::sendMessage(boost::shared_ptr<Message> message) {
#ifdef DEBUG_MODE
    std::cout << "sending message" << std::endl;
#endif

    NetworkMessage msg(message, m_flags, m_version);
    std::vector<uint8_t> bytes = msg.toByteArray();
    boost::asio::write(m_socket, boost::asio::buffer(bytes, bytes.size()));
//    m_socket.write_some();
}
