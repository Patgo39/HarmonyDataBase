#include "../../include/models/rola.hpp"

Rola::Rola(int _id_performer, int _id_album, std::string _path, std::string _title, int _track, int _year, std::string _genre): 
    id_performer(_id_performer), 
    id_album(_id_album), 
    path(std::move(_path)), 
    title(std::move(_title)), 
    track(_track), year(_year), 
    genre(std::move(_genre)) {}

Rola::Rola(int _id_rola, int _id_performer, int _id_album, std::string _path, std::string _title, int _track, int _year, std::string _genre): 
    id_rola(_id_rola), 
    id_performer(_id_performer), 
    id_album(_id_album), 
    path(std::move(_path)), 
    title(std::move(_title)), 
    track(_track), year(_year), 
    genre(std::move(_genre)) {}