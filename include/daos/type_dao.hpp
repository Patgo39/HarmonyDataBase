#ifndef TYPE_DAO_HPP
#define TYPE_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/type.hpp"
#include "../db/database_conection_manager.hpp"

using TypeStorage = decltype(
    sqlite_orm::make_storage("",
                  sqlite_orm::make_table("types",
                     sqlite_orm::make_column("id_type", &Type::id_type, 
            sqlite_orm::primary_key().autoincrement()),
                     sqlite_orm::make_column("description",
                             &Type::description))));

class TypeDao {
    TypeStorage storage;

public:
    TypeDao();
};

#endif