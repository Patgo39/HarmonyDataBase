#include "../../include/models/album.hpp"

Album::Album(): 
    id_album(0),
    path("Unknown"),
    name("Unknown"),
    year(0)
{
    auto now = std::chrono::system_clock::now();
    std::time_t time_c = std::chrono::system_clock::to_time_t(now);
    std::tm* local_date = std::localtime(&time_c);
    int current_year = local_date->tm_year+1900;
    year = current_year;
}


int Album::getIdAlbum() const{
    return id_album;
}

void Album::setIdAlbum(int idAlbum){
    id_album = idAlbum;
}

std::string Album::getPath() const{
    return path;
}

void Album::setPath(const std::string &path_){
    if(path_.empty()){
        path = "Unknown";
    }else{
        this->path = path;
    }

}

std::string Album::getName() const{
    return name;
}

void Album::setName(const std::string &name_){
    if(name_.empty()){
        name = "Unknown";
    }else{
        this->name = name_;
    }
}

int Album::getYear() const{
    return year;
}

void Album::setYear(int year_){

    auto now = std::chrono::system_clock::now();
    std::time_t time_c = std::chrono::system_clock::to_time_t(now);
    std::tm* local_date = std::localtime(&time_c);
    int current_year = local_date->tm_year+1900;

    if(year < 1000 || year > current_year){
        throw std::invalid_argument("Year has an invalid format.");
    }
    
}




