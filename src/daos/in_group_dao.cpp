#include "../../include/daos/in_group_dao.hpp"

InGroupDao::InGroupDao() : 
    storage(
        sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
                sqlite_orm::make_table("in_group",
                sqlite_orm::make_column("id_person", &InGroup::id_person),
                sqlite_orm::make_column("id_group", &InGroup::id_group),
                sqlite_orm::primary_key(&InGroup::id_person, &InGroup::id_group),
                sqlite_orm::foreign_key(&InGroup::id_person).references(&Person::id_person).on_delete.restrict_().on_update.cascade(),
                sqlite_orm::foreign_key(&InGroup::id_group).references(&Group::id_group).on_delete.restrict_().on_update.cascade()))
    ){}