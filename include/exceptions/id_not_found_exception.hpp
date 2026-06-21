#ifndef ID_NOT_FOUND_EXCEPTION_HPP
#define ID_NOT_FOUND_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class IdNotFoundException : public std::runtime_error{
    public:
    IdNotFoundException(const std::string &message) : std::runtime_error(message){}

};

#endif