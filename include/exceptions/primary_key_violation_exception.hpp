#ifndef PRIMARY_KEY_EXCEPTION_HPP
#define PRIMARY_KEY_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class PrimaryKeyViolationException : public std::runtime_error{
    public:
    PrimaryKeyViolationException(const std::string &message) : std::runtime_error(message){}

};

#endif