#include <iostream>
#include <messagefactory.hpp>
#include <connection.hpp>
#include <thread>
#include <boost/enable_shared_from_this.hpp>
#include <boost/thread.hpp>

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
            boost::thread thread([connection](){
                std::cout << "running thread" << std::endl;
                connection->start();

//                boost::shared_ptr<Message> msg(
//                            MessageFactory::createLoginMessageRes(LoginMessageRes::NOERROR)
//                            );

//                connection->sendMessage(msg);
            });

            start();
        } else {
            std::cout << "error while accepting client" << std::endl;
            connection.reset();
        }

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

        boost::shared_ptr<Connection> connection( new Connection(m_io) );
        boost::asio::ip::tcp::endpoint ep( boost::asio::ip::address::from_string("127.0.0.1"), 5555);
        connection->connect(ep);

        boost::shared_ptr<Message> msg ( MessageFactory::createLoginMessage("nick") );

//        m_msg.reset(
//                    new NetworkMessage(msg, 0, ProtocolVersion::v1_0())
//                    );

        connection->sendMessage(msg);
//        connection->sendMessage(msg);
    }

private:
    boost::asio::io_service& m_io;
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
            io_service.run();
        } else {
            std::cerr << "unrecognized option" << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }


    return 0;
#endif
}
