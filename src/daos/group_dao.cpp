#include "../../include/daos/group_dao.hpp"

GroupDao::GroupDao() : 
    storage(
        sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
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
                            &Group::getEndDate)))
    )
{}

std::vector<Group> GroupDao::findAll(){
    std::vector groups = storage.get_all<Group>();
    return groups;
}

std::optional<Group> GroupDao::getByID(int id_group){
    std::vector<Group> groups = storage.get_all<Group>(
                sqlite_orm::where(sqlite_orm::eq(&Group::getIdGroup, id_group)));

    std::optional<Group> group = std::nullopt;

    if(groups.size() == 1){
        group = groups[0];
    }

    return group;
}
    
int GroupDao::save(Group group){
    int id_group = storage.insert(group);
    return id_group;
}
    
void GroupDao::deleteById(int id_group){
    if(!exists(id_group)){
        throw IdNotFoundException("Error: Non-existent Group to delete.");
    }

    storage.remove<Group>(id_group);
}
    
void GroupDao::update(int id_group, Group group){
    if(!exists(id_group)){
        throw IdNotFoundException("Error: Non-existent Group to delete.");
    }

    group.setIdGroup(id_group);
    storage.update(group);
}
    
bool GroupDao::exists(int id_group){
    std::vector<Group> groups = storage.get_all<Group>(
	sqlite_orm::where(sqlite_orm::eq(&Group::getIdGroup, id_group)));
	
	return groups.size() == 1;
}
    