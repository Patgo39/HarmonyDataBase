#include "../../include/models/rola.hpp"

int Rola::getCurrentYear() const {
  auto now = std::chrono::system_clock::now();
  std::time_t time_c = std::chrono::system_clock::to_time_t(now);
  std::tm *local_date = std::localtime(&time_c);
  return local_date->tm_year + 1900;
}

Rola::Rola()
    : id_rola(0), id_performer(0), id_album(0), path("Unknown"),
      title("Unknown"), track(0), genre("Unknown") {
  year = getCurrentYear();
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
  path = path_.empty() ? "Unknown" : path_;
}

void Rola::setTitle(const std::string &title_) {
  title = title_.empty() ? "Unknown" : title_;
}

void Rola::setTrack(int track_) {
  if (track_ < 0) {
    throw std::invalid_argument("Track number cannot be negative.");
  }
  track = track_;
}

void Rola::setYear(int year_) {
  if (year_ < 1000 || year_ > getCurrentYear()) {
    throw std::invalid_argument("Year has an invalid format.");
  }
  year = year_;
}

void Rola::setGenre(const std::string &genre_) {
  genre = genre_.empty() ? "Unknown" : genre_;
}