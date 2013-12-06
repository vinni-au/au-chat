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
               ProtocolVersion version = ProtocolVersion::v1_0());

    tcp::socket& socket() {
        return m_socket;
    }

    void start();

    void handleReadHeader(const boost::system::error_code& err);

    virtual void sendMessage(boost::shared_ptr<NetworkMessage> message);

signals:
    void messageReceived(boost::shared_ptr<NetworkMessage> message);

private:
    tcp::socket m_socket;
    ProtocolVersion m_version;
    static const int MAX_LEN = 1024;
    char m_data[MAX_LEN];
};

#endif // CONNECTION_HPP
