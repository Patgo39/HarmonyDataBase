#include "../../include/daos/group_dao.hpp"

GroupDao::GroupDao() : 
    storage(
        sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
                  sqlite_orm::make_table("groups",
                     sqlite_orm::make_column("id_group", &Group::id_group, 
            sqlite_orm::primary_key().autoincrement()),
                     sqlite_orm::make_column("name",
                             &Group::name),
                     sqlite_orm::make_column("start_date",
                             &Group::start_date),
                     sqlite_orm::make_column("end_date",
                             &Group::end_date)))
    ){}