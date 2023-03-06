#ifdef __cpp_exceptions
#include "Exceptions.hpp"

namespace System
{

    ESPException::ESPException(esp_err_t error) : error(error) {}

    const char *ESPException::reason() const noexcept
    {
        return esp_err_to_name(error);
    }

}
#endif
