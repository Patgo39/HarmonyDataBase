#include "../../include/daos/performer_dao.hpp"

PerformerDao::PerformerDao() : 
    storage(
        sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
                  sqlite_orm::make_table("performers",
                     sqlite_orm::make_column("id_performer", &Performer::id_performer, 
            sqlite_orm::primary_key().autoincrement()),
                sqlite_orm::make_column("id_type",
                             &Performer::id_type),
                sqlite_orm::make_column("name",
                             &Performer::name),
                sqlite_orm::foreign_key(&Performer::id_type).references(&Type::id_type)
            .on_delete.restrict_().on_update.cascade()))
    ){}