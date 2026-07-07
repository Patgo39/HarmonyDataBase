#include "../../include/models/rola.hpp"

Rola::Rola() : 
  id_rola(0),
  id_album(0),
  id_performer(0),
  path("Unknown"),
  title("Unknown"),
  track(0),
  year(time_utils::get_current_year()),
  genre("Unknown"){

}

int Rola::getIdRola() const { return id_rola; }

int Rola::getIdPerformer() const { return id_performer; }

int Rola::getIdAlbum() const { return id_album; }

std::string Rola::getPath() const { return path; }

std::string Rola::getTitle() const { return title; }

int Rola::getTrack() const { return track; }

int Rola::getYear() const { return year; }

std::string Rola::getGenre() const { return genre; }

void Rola::setIdRola(int idRola_) {
  if (idRola_ <= 0) {
    throw std::invalid_argument("Id can't be zero or negative.");
  }
  id_rola = idRola_;
}

void Rola::setIdPerformer(int idPerformer_) {
  if (idPerformer_ <= 0) {
    throw std::invalid_argument("Id can't be zero or negative.");
  }
  id_performer = idPerformer_;
}

void Rola::setIdAlbum(int idAlbum_) {
  if (idAlbum_ <= 0) {
    throw std::invalid_argument("Id can't be zero or negative.");
  }
  id_album = idAlbum_;
}

void Rola::setPath(const std::string &path_) {
  if (str_utils::is_white_spaces(path_)) {
    path = "Unknown";
  } else {
    path = str_utils::delete_extreme_whitespaces(path_);
  }
}

void Rola::setTitle(const std::string &title_) {
  if (str_utils::is_white_spaces(title_)) {
    title = "Unknown";
  } else {
    title = str_utils::delete_extreme_whitespaces(title_);
  }
}

void Rola::setTrack(int track_) {
  if (track_ < 0) {
    throw std::invalid_argument("Track number cannot be negative.");
  }
  track = track_;
}

void Rola::setYear(int year_) {
  if (!time_utils::is_year_valid(year_)) {
    throw std::invalid_argument("Year has an invalid format.");
  }
  year = year_;
}

void Rola::setGenre(const std::string &genre_) {
  if (str_utils::is_white_spaces(genre_)) {
    genre = "Unknown";
  } else {
    genre = str_utils::delete_extreme_whitespaces(genre_);
  }
}