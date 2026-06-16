#include "../../include/daos/person_dao.hpp"

PersonDao::PersonDao()
: storage(sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
			      sqlite_orm::make_table("persons",
					 sqlite_orm::make_column("id_person", &Person::id_person, 
            sqlite_orm::primary_key().autoincrement()),
					 sqlite_orm::make_column("stage_name",
						     &Person::stage_name),
					 sqlite_orm::make_column("real_name",
						     &Person::real_name),
					 sqlite_orm::make_column("birth_date",
						     &Person::birth_date),
					 sqlite_orm::make_column("death_date",
						     &Person::death_date)))
) {


	storage.sync_schema();

}