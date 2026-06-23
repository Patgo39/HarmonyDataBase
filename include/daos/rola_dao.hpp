#ifndef ROLA_DAO_HPP
#define ROLA_DAO_HPP

#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/rola.hpp"
#include "../models/performer.hpp"
#include "../models/album.hpp"
#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "dao_interface.hpp"

using RolaStorage = decltype(
    sqlite_orm::make_storage("",
                  sqlite_orm::make_table("rolas",
                     sqlite_orm::make_column("id_rola", 
                        &Rola::getIdRola,
                        &Rola::setIdRola, 
            sqlite_orm::primary_key().autoincrement()),
                     sqlite_orm::make_column("id_performer",
                            &Rola::getIdPerformer,
                            &Rola::setIdPerformer),
                     sqlite_orm::make_column("id_album",
                            &Rola::getIdAlbum,
                            &Rola::setIdAlbum),
                     sqlite_orm::make_column("path",
                            &Rola::getPath,
                            &Rola::setPath),
                     sqlite_orm::make_column("title",
                            &Rola::getTitle,
                            &Rola::setTitle),
                     sqlite_orm::make_column("track",
                            &Rola::getTrack,
                            &Rola::setTrack),
                     sqlite_orm::make_column("year",
                            &Rola::getYear,
                            &Rola::setYear),
                     sqlite_orm::make_column("genre",
                            &Rola::getGenre,
                            &Rola::setGenre),
                     sqlite_orm::foreign_key(&Rola::getIdPerformer).
                     references(&Performer::getIdPerformer).
                     on_delete.restrict_().on_update.cascade(),
                     sqlite_orm::foreign_key(&Rola::getIdAlbum).
                     references(&Album::getIdAlbum).
                     on_delete.restrict_().on_update.cascade())));

class RolaDao : public DaoInterface<Rola> {
    RolaStorage storage;

public:
    RolaDao();

    std::vector<Rola> findAll() override;
    std::optional<Rola> getByID(int id_rola) override;
    int save(Rola rola) override;
    void deleteById(int id_rola) override;
    void update(int id_rola, Rola rola) override;
    bool exists(int id_rola) override;
};

#endif