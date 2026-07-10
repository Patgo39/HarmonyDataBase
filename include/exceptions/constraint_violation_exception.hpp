#ifndef CONSTRAINT_VIOLATION_EXCEPTION_HPP
#define CONSTRAINT_VIOLATION_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class ConstraintViolationException : public std::runtime_error{
    public:
    ConstraintViolationException(const std::string &message) : std::runtime_error(message){}

};

#endif