#ifndef PERFORMER_DAO_HPP
#define PERFORMER_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/performer.hpp"
#include "../models/type.hpp"
#include "../db/database_conection_manager.hpp"

using PerformerStorage = decltype(
    sqlite_orm::make_storage("",
                  sqlite_orm::make_table("performers",
                     sqlite_orm::make_column("id_performer", &Performer::id_performer, 
            sqlite_orm::primary_key().autoincrement()),
                    sqlite_orm::make_column("id_type",
                             &Performer::id_type),
                    sqlite_orm::make_column("name",
                             &Performer::name),
                    sqlite_orm::foreign_key(&Performer::id_type).references(&Type::id_type))));

class PerformerDao {
    PerformerStorage storage;

public:
    PerformerDao();
};

#endif