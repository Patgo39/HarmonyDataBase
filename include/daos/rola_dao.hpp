#ifndef ROLA_DAO_HPP
#define ROLA_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/rola.hpp"
#include "../models/performer.hpp"
#include "../models/album.hpp"
#include "../db/database_conection_manager.hpp"

using RolaStorage = decltype(
    sqlite_orm::make_storage("",
                  sqlite_orm::make_table("rolas",
                     sqlite_orm::make_column("id_rola", &Rola::id_rola, 
            sqlite_orm::primary_key().autoincrement()),
                sqlite_orm::make_column("id_performer",
                             &Rola::id_performer),
                sqlite_orm::make_column("id_album",
                             &Rola::id_album),
                sqlite_orm::make_column("path",
                             &Rola::path),
                sqlite_orm::make_column("title",
                             &Rola::title),
                sqlite_orm::make_column("track",
                             &Rola::track),
                sqlite_orm::make_column("year",
                             &Rola::year),
                sqlite_orm::make_column("genre",
                             &Rola::genre),
                sqlite_orm::foreign_key(&Rola::id_performer).
                references(&Performer::id_performer).
                on_delete.restrict_().on_update.cascade(),
                sqlite_orm::foreign_key(&Rola::id_album).
                references(&Album::getIdAlbum).
                on_delete.restrict_().on_update.cascade())));

class RolaDao {
    RolaStorage storage;

public:
    RolaDao();
};

#endif