#include "connection.hpp"

Connection::Connection(boost::asio::io_service & ioservice)
    : m_socket(ioservice)
{
}

void Connection::start() {
#ifdef DEBUG_MODE
    std::cout << "starting connection" << std::endl;
#endif

    boost::asio::async_read(m_socket,
                            boost::asio::buffer(m_data, 5),
                            boost::bind(&Connection::handleReadHeader, this,
                                        boost::asio::placeholders::error));

//    m_socket.async_read_some(
//                boost::asio::buffer(m_data, MAX_LEN),
//                boost::bind(&Connection::handleRead, this,
//                            boost::asio::placeholders::error,
//                            boost::asio::placeholders::bytes_transferred)
//                );
}

void Connection::handleRead(const boost::system::error_code &err,
                            size_t bytes_transferred)
{
#ifdef DEBUG_MODE
    std::cout << "Connection::handleRead [" <<
                 "bytes_transferred = " << bytes_transferred <<
              "]" << std::endl;

    for (size_t i = 0; i < bytes_transferred; ++i) {
        std::cout << std::hex << m_data[i] << " ";
    }
    std::cout << std::endl;
#endif

}

void Connection::handleReadHeader(const boost::system::error_code &err) {
#ifdef DEBUG_MODE
    std::cout << "Connection::handleReadHeader" << std::endl;

    for (size_t i = 0; i < 5; ++i) {
        std::cout << std::hex << m_data[i] << " ";
    }
    std::cout << std::endl;

#endif
}

void Connection::sendMessage(boost::shared_ptr<NetworkMessage> message) {

}
