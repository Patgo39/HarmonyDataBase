#include "../../include/daos/rola_dao.hpp"

RolaDao::RolaDao() : 
    storage(
        sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
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
                on_delete.restrict_().on_update.cascade()))
    ){}