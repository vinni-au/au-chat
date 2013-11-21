#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <cstdint>
#include <string>


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

protected:
    Type m_type;

    friend class MessageFactory;
};

#endif // MESSAGE_HPP
