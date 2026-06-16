#ifndef PERSON_DAO_HPP
#define PERSON_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/person.hpp"
#include "../db/database_conection_manager.hpp"


using PersonStorage = decltype(
    sqlite_orm::make_storage("",
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
						     &Person::death_date))));

class PersonDao{

    PersonStorage storage;

    public:

    PersonDao();

};
#endif