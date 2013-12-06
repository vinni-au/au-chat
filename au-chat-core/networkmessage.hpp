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

    inline bool operator<(const ProtocolVersion& other) const {
        return vmajor < other.vmajor ||
                (vmajor == other.vmajor && vminor < other.vminor);
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

typedef union {
    uint32_t _32;
    uint8_t _8[4];
} _32to8_t;

typedef union {
    uint16_t _16;
    uint8_t _8[2];
} _16to8_t;

class NetworkMessage
{
public:

    struct Header {
        Header(uint8_t type, uint32_t length, uint32_t flags, ProtocolVersion version)
            : type(type)
            , length(length)
            , flags(flags)
            , version(version)
        {   }

        static const size_t SIZE = 11;

        uint8_t  type;
        uint32_t length;
        uint32_t flags;
        ProtocolVersion version;

        std::vector<uint8_t> toByteArray() {
            _32to8_t _32to8;
            _16to8_t _16to8;

            size_t cur = 0;
            std::vector<uint8_t> result(11);
            result[cur++] = type;

            _32to8._32 = length;
            for (int i = 0; i < 4; ++i)
                result[cur++] = _32to8._8[i];

            _32to8._32 = flags;
            for (int i = 0; i < 4; ++i)
                result[cur++] = _32to8._8[i];

            _16to8._16 = version.packed();
            result[cur++] = _16to8._8[0];
            result[cur++] = _16to8._8[1];

            return result;
        }

        static Header fromByteArray(std::vector<uint8_t> array) {
            if (array.size() != SIZE) {
                throw std::logic_error("Wrong header length");
            }

            _32to8_t _32to8;
            _16to8_t _16to8;

            size_t cur = 0;
            uint8_t type_ = array[cur++];

            for (int i = 0; i < 4; ++i)
                _32to8._8[i] = array[cur++];
            uint32_t len = _32to8._32;

            for (int i = 0; i < 4; ++i)
                _32to8._8[i] = array[cur++];
            uint32_t fl = _32to8._32;
            return Header(type_, len, fl, ProtocolVersion::v1_0());
        }
    };

    enum Flags {
        Compressed  = 0x00000001,
        Encrypted   = 0x00000002
    };

    NetworkMessage(boost::shared_ptr<Message> message,
                   uint32_t flags, ProtocolVersion version);

    std::vector<uint8_t> toByteArray();


private:

    Header m_header;

    boost::shared_ptr<Message> m_message;
};

#endif // NETWORKMESSAGE_HPP
