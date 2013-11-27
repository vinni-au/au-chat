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

    // to JSON string
    virtual std::string toJSON() = 0;

    uint8_t type() {
        return uint8_t(m_type);
    }

protected:
    Type m_type;

    friend class MessageFactory;
};

#endif // MESSAGE_HPP
