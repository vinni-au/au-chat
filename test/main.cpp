#include <iostream>
#include <messagefactory.hpp>
#include <connection.hpp>
#include <thread>
#include <boost/enable_shared_from_this.hpp>

//#define MESSAGE_TEST
#define CONNECTION_TEST

#ifdef CONNECTION_TEST
using boost::asio::ip::tcp;

class server_test : public boost::enable_shared_from_this<server_test> {
public:
    server_test(boost::asio::io_service& io_service, short port)
        : m_io(io_service), m_acceptor(io_service, tcp::endpoint(tcp::v4(), port))
    {
        std::fill(m_data, m_data+1024, 0);
    }

    void start() {
        std::cout << "starting test server..." << std::endl;

        boost::shared_ptr<Connection> connection( new Connection(m_io) );
        m_acceptor.async_accept(connection->socket(),
                                boost::bind(&server_test::handleAccept,
                                            this, connection,
                                            boost::asio::placeholders::error));
    }

private:
    void handleAccept(boost::shared_ptr<Connection> connection,
                      const boost::system::error_code& err) {
        std::cout << "client accepted" << std::endl;

        if (!err) {
//            connection->start();
            boost::asio::async_read(connection->socket(),
                                    boost::asio::buffer(m_data, 5),
                                    boost::bind(&server_test::handleReadHeader,
                                                this,
                                                boost::asio::placeholders::error));
        } else {
            std::cout << "error while accepting client" << std::endl;
            connection.reset();
        }
    }

    void handleReadHeader(const boost::system::error_code& err) {
        std::cout << "handlerReadHeader" << std::endl;
        for (int i = 0; i < 5; ++i) {
            std::cout << (int)m_data[i] << " ";
        }
        std::cout << std::endl;
    }

    boost::asio::io_service& m_io;
    tcp::acceptor m_acceptor;
    char m_data[1024];
};


class client_test {
public:
    client_test(boost::asio::io_service& io_service, short port)
        : m_io(io_service),
//          m_acceptor(io_service, tcp::endpoint(tcp::v4(), port)),
          m_resolver(io_service)
    {
    }

    void start() {
        std::cout << "starting test client..." << std::endl;

//        tcp::resolver::query query(tcp::v4(), "127.0.0.1", "5555");
//        tcp::resolver::iterator iterator = m_resolver.resolve(query);


//        s.connect(*iterator);

        boost::shared_ptr<Message> msg ( MessageFactory::createLoginMessage("nick") );


        m_msg.reset (
                    new NetworkMessage(
                            msg,
                        0, ProtocolVersion::v1_0()
                        ) );

        size_t request_len = m_msg->length();
        std::vector<uint8_t> bytes = m_msg->toByteArray();
        char buf[1024];
        std::copy(bytes.begin(), bytes.end(), buf);
        for (int i = 0; i < 5; ++i) {
            std::cout << (int)buf[i] << " ";
        }
        std::cout << std::endl << request_len << std::endl;
        boost::asio::ip::tcp::endpoint ep( boost::asio::ip::address::from_string("127.0.0.1"), 5555);
        tcp::socket s(m_io);
        s.connect(ep);
        s.write_some(boost::asio::buffer(buf, request_len));
//        boost::asio::write(s, boost::asio::buffer( buf, request_len ));
    }

private:
    boost::asio::io_service& m_io;
//    tcp::acceptor m_acceptor;
    tcp::resolver m_resolver;

    boost::shared_ptr<NetworkMessage> m_msg;
};

#endif

int main(int argc, char* argv[])
{
#ifdef MESSAGE_TEST
    std::cout << MessageFactory::createFetchMessage(12)->toJSON() << std::endl;
    return 0;
#endif

#ifdef CONNECTION_TEST
    if (argc < 2) {
        std::cout << "Usage: ./test (--server|--client)" << std::endl;
        return 0;
    }

    try {
        boost::asio::io_service io_service;

        if ( std::string(argv[1]) == "--server" ) {
            server_test server(io_service, 5555);
            server.start();
            io_service.run();
        } else if ( std::string(argv[1]) == "--client" ) {
            client_test client(io_service, 5555);
            client.start();
        } else {
            std::cerr << "unrecognized option" << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }


    return 0;
#endif
}
