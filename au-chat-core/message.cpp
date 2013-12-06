#include "message.hpp"

std::string Message::json() {
    if (!m_json) {
        m_json.reset( new std::string( toJSON()) );
    }

    return *m_json.get();
}

