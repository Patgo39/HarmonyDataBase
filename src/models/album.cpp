#include "../../include/models/album.hpp"

Album::Album(std::string _path, std::string _name, int _year): 
    path(std::move(_path)), 
    name(std::move(_name)), 
    year(_year) {}

Album::Album(int _id_album, std::string _path, std::string _name, int _year): 
    id_album(_id_album), 
    path(std::move(_path)), 
    name(std::move(_name)), 
    year(_year) {}