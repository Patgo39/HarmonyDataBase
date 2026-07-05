#include "../../include/daos/album_dao.hpp"

AlbumDao::AlbumDao() {
  DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
  db.createAndStartDatabase();
  storage = db.getHarmonyStorage();
}

std::vector<Album> AlbumDao::findAll() {

  std::vector<Album> album_vector = storage->get_all<Album>();
  return album_vector;
}

std::optional<Album> AlbumDao::getByID(int _id_album) {
  std::vector<Album> albums = storage->get_all<Album>(
      sqlite_orm::where(sqlite_orm::eq(&Album::getIdAlbum, _id_album)));

  std::optional<Album> album = std::nullopt;
  if (albums.size() == 1) album = albums[0];

  return album;
}

int AlbumDao::save(Album album) {
  int id_album = storage->insert(album);
  return id_album;
}

void AlbumDao::deleteById(int _id_album) {
  if (!exists(_id_album)) {
    throw IdNotFoundException("Error: Non-existent Album to delete.");
  }

  storage->remove<Album>(_id_album);
}

void AlbumDao::update(int _id_album, Album album) {
  if (!exists(_id_album)) {
    throw IdNotFoundException("Error: Non-existent Album to update.");
  }

  album.setIdAlbum(_id_album);
  storage->update(album);
}

bool AlbumDao::exists(int _id_album) {
  std::vector<Album> album = storage->get_all<Album>(
      sqlite_orm::where(sqlite_orm::eq(&Album::getIdAlbum, _id_album)));

  return album.size() == 1;
}