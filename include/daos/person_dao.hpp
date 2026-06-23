#ifndef PERSON_DAO_HPP
#define PERSON_DAO_HPP

#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/person.hpp"
#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "dao_interface.hpp"

using PersonStorage = decltype(
    sqlite_orm::make_storage("",
                  sqlite_orm::make_table("persons",
                     sqlite_orm::make_column("id_person", 
                        &Person::getIdPerson,
                        &Person::setIdPerson, 
            sqlite_orm::primary_key().autoincrement()),
                     sqlite_orm::make_column("stage_name",
                            &Person::getStageName,
                            &Person::setStageName),
                     sqlite_orm::make_column("real_name",
                            &Person::getRealName,
                            &Person::setRealName),
                     sqlite_orm::make_column("birth_date",
                            &Person::getBirthDate,
                            &Person::setBirthDate),
                     sqlite_orm::make_column("death_date",
                            &Person::getDeathDate,
                            &Person::setDeathDate))));

class PersonDao : public DaoInterface<Person> {
    PersonStorage storage;

public:
    PersonDao();

    std::vector<Person> findAll() override;
    std::optional<Person> getByID(int id_person) override;
    int save(Person person) override;
    void deleteById(int id_person) override;
    void update(int id_person, Person person) override;
    bool exists(int id_person) override;
};

#endif