#ifndef ALBUM_DAO_HPP
#define ALBUM_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../models/album.hpp"
#include "dao_interface.hpp"


class AlbumDao : public DaoInterface<Album> {
  std::shared_ptr<harmony_storage> storage;

public:
  AlbumDao();
  std::vector<Album> findAll() override;
  std::optional<Album> getByID(int _id_album) override;
  int save(Album album) override;
  void deleteById(int _id_album) override;
  void update(int _id_album, Album album) override;
  bool exists(int _id_album) override;
};
#endif