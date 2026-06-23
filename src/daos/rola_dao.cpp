#include "../../include/daos/rola_dao.hpp"

RolaDao::RolaDao() : 
    storage(
        sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
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
                     on_delete.restrict_().on_update.cascade()))
    )
{}

std::vector<Rola> RolaDao::findAll() {
    std::vector rolas = storage.get_all<Rola>();
    return rolas;
}

std::optional<Rola> RolaDao::getByID(int id_rola) {
    std::vector<Rola> rolas = storage.get_all<Rola>(
                sqlite_orm::where(sqlite_orm::eq(&Rola::getIdRola, id_rola)));

    std::optional<Rola> rola = std::nullopt;

    if(rolas.size() == 1) {
        rola = rolas[0];
    }

    return rola;
}
    
int RolaDao::save(Rola rola) {
    int id_rola = storage.insert(rola);
    return id_rola;
}
    
void RolaDao::deleteById(int id_rola) {
    if(!exists(id_rola)) {
        throw IdNotFoundException("Error: Non-existent Rola to delete.");
    }

    storage.remove<Rola>(id_rola);
}
    
void RolaDao::update(int id_rola, Rola rola) {
    if(!exists(id_rola)) {
        throw IdNotFoundException("Error: Non-existent Rola to update.");
    }

    rola.setIdRola(id_rola);
    storage.update(rola);
}
    
bool RolaDao::exists(int id_rola) {
    std::vector<Rola> rolas = storage.get_all<Rola>(
    sqlite_orm::where(sqlite_orm::eq(&Rola::getIdRola, id_rola)));
    
    return rolas.size() == 1;
}