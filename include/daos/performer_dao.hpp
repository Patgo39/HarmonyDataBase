#ifndef PERFORMER_DAO_HPP
#define PERFORMER_DAO_HPP

#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/performer.hpp"
#include "../models/type.hpp"
#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "dao_interface.hpp"

using PerformerStorage = decltype(
    sqlite_orm::make_storage("",
                  sqlite_orm::make_table("performers",
                     sqlite_orm::make_column("id_performer", 
                        &Performer::getIdPerformer,
                        &Performer::setIdPerformer, 
            sqlite_orm::primary_key().autoincrement()),
                     sqlite_orm::make_column("id_type",
                            &Performer::getIdType,
                            &Performer::setIdType),
                     sqlite_orm::make_column("name",
                            &Performer::getName,
                            &Performer::setName),
                     sqlite_orm::foreign_key(&Performer::getIdType).
                     references(&Type::id_type).on_delete.restrict_().on_update.cascade())));

class PerformerDao : public DaoInterface<Performer> {
    PerformerStorage storage;

public:
    PerformerDao();

    std::vector<Performer> findAll() override;
    std::optional<Performer> getByID(int id_performer) override;
    int save(Performer performer) override;
    void deleteById(int id_performer) override;
    void update(int id_performer, Performer performer) override;
    bool exists(int id_performer) override;
};

#endif