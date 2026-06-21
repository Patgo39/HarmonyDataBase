#ifndef ALBUM_DAO_HPP
#define ALBUM_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/album.hpp"
#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "dao_interface.hpp"


using AlbumStorage = decltype(
    sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
			      sqlite_orm::make_table("albums",
					 sqlite_orm::make_column("id_album", 
						&Album::getIdAlbum,
						&Album::setIdAlbum, 
            sqlite_orm::primary_key().autoincrement()),
					 sqlite_orm::make_column("path",
						    &Album::getPath,
							&Album::setPath),
					 sqlite_orm::make_column("name",
						    &Album::setName,
							&Album::getName),
					 sqlite_orm::make_column("year",
						    &Album::setYear,
							&Album::getYear))));

class AlbumDao: public DaoInterface<Album>{

    AlbumStorage storage;

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