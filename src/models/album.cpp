#include "../../include/models/album.hpp"

Album::Album() : 
  id_album(0), 
  path("Unknown"), 
  name("Unknown"), 
  year(time_utils::get_current_year()) 
{}

int Album::getIdAlbum() const { return id_album; }

void Album::setIdAlbum(int idAlbum) {
  if (idAlbum <= 0) {
    throw std::invalid_argument("Id can't be zero or negative.");
  }
  id_album = idAlbum;
}

std::string Album::getPath() const { return path; }

void Album::setPath(const std::string &path_) {
  if (str_utils::is_white_spaces(path_)) {
    path = "Unknown";
  } else {
    this->path = str_utils::delete_extreme_whitespaces(path_);
  }
}

std::string Album::getName() const { return name; }

void Album::setName(const std::string &name_) {
  if (str_utils::is_white_spaces(name_)) {
    name = "Unknown";
  } else {
    name = str_utils::delete_extreme_whitespaces(name_);
  }
}

int Album::getYear() const { return year; }

void Album::setYear(int year_) {
  if (!time_utils::is_year_valid(year_)) {
    throw std::invalid_argument("Invalid value for year, year must be {YYYY} > 1000 && {YYYY} < current_year.");
  }

  year = year_;
}
