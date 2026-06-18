#include "../../include/daos/type_dao.hpp"

TypeDao::TypeDao() : 
    storage(
        sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
                  sqlite_orm::make_table("types",
                     sqlite_orm::make_column("id_type", &Type::id_type, 
            sqlite_orm::primary_key().autoincrement()),
                     sqlite_orm::make_column("description",
                             &Type::description)))
    ){}