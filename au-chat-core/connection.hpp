#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <QObject>
#include "networkmessage.hpp"
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Connection : public QObject
{
    Q_OBJECT
public:
    Connection(boost::asio::io_service& ioservice,
               ProtocolVersion version = ProtocolVersion::v1_0(),
               uint32_t flags = 0);

    //TODO: Connection принимает socket

    tcp::socket& socket() {
        return m_socket;
    }

    // For server
    void start();

    // For client
    void connect(tcp::endpoint &ep);

    void handleReadHeader(const boost::system::error_code& err);
    void handleReadBody(NetworkMessage::Header header, const boost::system::error_code& err);

    void sendMessage(boost::shared_ptr<Message> message);

signals:
    void messageReceived(boost::shared_ptr<NetworkMessage> message);

private:
    tcp::socket m_socket;
    ProtocolVersion m_version;
    static const int MAX_LEN = 1024;
    char m_data[MAX_LEN];

    uint32_t m_flags;
};

#endif // CONNECTION_HPP
