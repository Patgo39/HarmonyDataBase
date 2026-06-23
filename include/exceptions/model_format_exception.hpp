#ifndef MODEL_FORMAT_EXCEPTION_HPP
#define MODEL_FORMAT_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class ModelFormatException : public std::runtime_error{
    public:
    ModelFormatException(const std::string &message) : std::runtime_error(message){}

};


#endif // MODEL_FORMAT_EXCEPTION_HPP
