#include "../../include/daos/album_dao.hpp"

AlbumDao::AlbumDao() : 
    storage(
        sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
			      sqlite_orm::make_table("albums",
					 sqlite_orm::make_column("id_person", &Album::id_album, 
            sqlite_orm::primary_key().autoincrement()),
					 sqlite_orm::make_column("path",
						     &Album::path),
					 sqlite_orm::make_column("name",
						     &Album::name),
					 sqlite_orm::make_column("year",
						     &Album::year)))
    ){}