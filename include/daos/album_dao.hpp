#ifndef ALBUM_DAO_HPP
#define ALBUM_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/album.hpp"
#include "../db/database_conection_manager.hpp"


using AlbumStorage = decltype(
    sqlite_orm::make_storage("",
			      sqlite_orm::make_table("albums",
					 sqlite_orm::make_column("id_person", &Album::id_album, 
            sqlite_orm::primary_key().autoincrement()),
					 sqlite_orm::make_column("path",
						     &Album::path),
					 sqlite_orm::make_column("name",
						     &Album::name),
					 sqlite_orm::make_column("year",
						     &Album::year))));

class AlbumDao{

    AlbumStorage storage;

    public:

    AlbumDao();

};
#endif