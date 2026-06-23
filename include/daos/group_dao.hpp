#ifndef GROUP_DAO_HPP
#define GROUP_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/group.hpp"
#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "dao_interface.hpp"

using GroupStorage = decltype(
    sqlite_orm::make_storage("",
                  sqlite_orm::make_table("groups",
                     sqlite_orm::make_column("id_group", 
                        &Group::setIdGroup,
                        &Group::getIdGroup, 
            sqlite_orm::primary_key().autoincrement()),
                     sqlite_orm::make_column("name",
                            &Group::getName,
                            &Group::setName),
                     sqlite_orm::make_column("start_date",
                            &Group::setStartDate,
                            &Group::getStartDate),
                     sqlite_orm::make_column("end_date",
                            &Group::setEndDate,
                            &Group::getEndDate))));

class GroupDao : public DaoInterface<Group>{
    GroupStorage storage;

public:
    GroupDao();

    std::vector<Group> findAll() override;
    std::optional<Group> getByID(int id_group) override;
    int save(Group group) override;
    void deleteById(int id_group) override;
    void update(int id_group, Group group) override;
    bool exists(int id_group) override;
};

#endif