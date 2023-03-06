#pragma once

#ifdef __cpp_exceptions

#include "esp_err.h"
#include <exception>

namespace System
{

    class ESPException : public std::exception
    {
    public:
        ESPException(esp_err_t error);

        virtual ~ESPException() {}
        virtual const char *reason() const noexcept;
        const esp_err_t error;
    };

/**
 * Macro to help converting IDF error codes into ESPException.
 */
#define CHECK_THROW(error_)                  \
    do                                       \
    {                                        \
        esp_err_t result = error_;           \
        if (result != ESP_OK)                \
            throw idf::ESPException(result); \
    } while (0)

/**
 * Macro to help converting IDF error codes into a child of ESPException.
 */
#define CHECK_THROW_SPECIFIC(error_, exception_type_) \
    do                                                \
    {                                                 \
        esp_err_t result = (error_);                  \
        if (result != ESP_OK)                         \
            throw exception_type_(result);            \
    } while (0)

} 

#endif 
