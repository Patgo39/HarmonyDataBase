#ifndef GROUP_DAO_HPP
#define GROUP_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/group.hpp"
#include "../db/database_conection_manager.hpp"

using GroupStorage = decltype(
    sqlite_orm::make_storage("",
                  sqlite_orm::make_table("groups",
                     sqlite_orm::make_column("id_group", &Group::id_group, 
            sqlite_orm::primary_key().autoincrement()),
                     sqlite_orm::make_column("name",
                             &Group::name),
                     sqlite_orm::make_column("start_date",
                             &Group::start_date),
                     sqlite_orm::make_column("end_date",
                             &Group::end_date))));

class GroupDao {
    GroupStorage storage;

public:
    GroupDao();
};

#endif