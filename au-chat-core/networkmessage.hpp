#ifndef NETWORKMESSAGE_HPP
#define NETWORKMESSAGE_HPP

#include "message.hpp"
#include <boost/shared_ptr.hpp>

struct ProtocolVersion {
    static ProtocolVersion v1_0() {
        return ProtocolVersion(1, 0);
    }

    uint16_t packed() {
        return uint16_t(vmajor << 8 | vminor);
    }

    static ProtocolVersion unpack(uint16_t packed) {
        return ProtocolVersion( uint8_t(packed >> 8),
                                uint8_t(packed & 0xFF) );
    }

    inline bool operator==(const ProtocolVersion& other) const {
        return vmajor == other.vmajor &&
                vminor == other.vminor;
    }

    inline bool operator!=(const ProtocolVersion& other) const {
        return vmajor != other.vmajor ||
                vminor != other.vminor;
    }

private:
    ProtocolVersion(uint8_t vmajor, uint8_t vminor) :
        vmajor(vmajor), vminor(vminor)
    {   }

    uint8_t vmajor;
    uint8_t vminor;
};

class NetworkMessage
{
public:

    enum Flags {
        Compressed  = 0x00000001,
        Encrypted   = 0x00000002
    };

    NetworkMessage(boost::shared_ptr<Message> message,
                   uint32_t flags, ProtocolVersion version);

    std::vector<uint8_t> toByteArray();

    uint32_t length() const
    { return m_length; }


private:

    uint32_t m_length;
    boost::shared_ptr<Message> m_message;
    uint32_t m_flags;
    uint16_t m_version;
};

#endif // NETWORKMESSAGE_HPP
