#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <cstdint>
#include <string>
#include <json_spirit/writer_template.h>
#include <json_spirit/reader_template.h>


/* abstract */
class Message
{
    
public:

    enum Type {
        Login,
        LoginRes,
        Fetch,
        Text,
        Send,
        //Logout,
        LogoutReq,
        ListUser,
        ListUserReq
    };

    std::string json();

    uint8_t type() const {
        return uint8_t(m_type);
    }

    size_t size() {
        return json().size();
    }

protected:
    // to JSON string
    virtual std::string toJSON() = 0;

    Type m_type;
    boost::shared_ptr<std::string> m_json;
    size_t m_size;

    friend class MessageFactory;
};

#endif // MESSAGE_HPP
