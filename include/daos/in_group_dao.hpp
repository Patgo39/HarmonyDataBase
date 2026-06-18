#ifndef IN_GROUP_DAO_HPP
#define IN_GROUP_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/in_group.hpp"
#include "../db/database_conection_manager.hpp"

using InGroupStorage = decltype(
    sqlite_orm::make_storage("",
                  sqlite_orm::make_table("in_group",
                     sqlite_orm::make_column("id_person", &InGroup::id_person),
                     sqlite_orm::make_column("id_group", &InGroup::id_group),
                     sqlite_orm::primary_key(&InGroup::id_person, &InGroup::id_group))));

class InGroupDao {
    InGroupStorage storage;

public:
    InGroupDao();
};

#endif