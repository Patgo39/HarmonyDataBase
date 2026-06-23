#ifndef IN_GROUP_DAO_HPP
#define IN_GROUP_DAO_HPP

#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include <utility>
#include "../models/in_group.hpp"
#include "../models/person.hpp"
#include "../models/group.hpp"
#include "../daos/person_dao.hpp"
#include "../daos/group_dao.hpp"
#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../exceptions/model_format_exception.hpp"

using InGroupStorage = decltype(
    sqlite_orm::make_storage("",
                sqlite_orm::make_table("in_group",
                sqlite_orm::make_column("id_person", &InGroup::getIdPerson, &InGroup::setIdPerson),
                sqlite_orm::make_column("id_group", &InGroup::getIdGroup, &InGroup::setIdGroup),
                sqlite_orm::primary_key(&InGroup::getIdPerson, &InGroup::getIdGroup),
                sqlite_orm::foreign_key(&InGroup::getIdPerson).
                references(&Person::getIdPerson).on_delete.restrict_().on_update.cascade(),
                sqlite_orm::foreign_key(&InGroup::getIdGroup).
                references(&Group::getIdGroup).on_delete.restrict_().on_update.cascade())));

class InGroupDao{
    InGroupStorage storage;

public:
    InGroupDao();

    std::vector<InGroup> findAll();
    std::vector<InGroup> getByIdPerson(int id_person);
    std::vector<InGroup> getByIdGroup(int id_group);
    std::optional<InGroup> getByCompositeID(int id_person, int id_group);
    std::pair<int, int> save(InGroup in_group);
    void deleteByIdPerson(int id_person);
    void deleteByIdGroup(int id_group);
    void deleteByCompositeId(int id_person, int id_group);
    void update(int id_person, int id_group, InGroup in_group);
    bool existsByIdPerson(int id_person);
    bool existsByIdGroup(int id_group);
    bool existsComposite(int id_person, int id_group);
};

#endif