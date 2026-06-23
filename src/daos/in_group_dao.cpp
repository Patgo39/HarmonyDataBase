#include "../../include/daos/in_group_dao.hpp"

InGroupDao::InGroupDao() : 
    storage(
        sqlite_orm::make_storage(DatabaseConectionManager::getInstance().getDatabasePath(),
                sqlite_orm::make_table("in_group",
                sqlite_orm::make_column("id_person", &InGroup::getIdPerson, &InGroup::setIdPerson),
                sqlite_orm::make_column("id_group", &InGroup::getIdGroup, &InGroup::setIdGroup),
                sqlite_orm::primary_key(&InGroup::getIdPerson, &InGroup::getIdGroup),
                sqlite_orm::foreign_key(&InGroup::getIdPerson).
                references(&Person::getIdPerson).on_delete.restrict_().on_update.cascade(),
                sqlite_orm::foreign_key(&InGroup::getIdGroup).
                references(&Group::getIdGroup).on_delete.restrict_().on_update.cascade()))
    ){}

std::vector<InGroup> InGroupDao::findAll(){
    std::vector in_groups = storage.get_all<InGroup>();
    return in_groups;
}

std::vector<InGroup> InGroupDao::getByIdPerson(int id_person){
    std::vector<InGroup> in_groups = storage.get_all<InGroup>(
                sqlite_orm::where(sqlite_orm::eq(&InGroup::getIdPerson, id_person)));
    return in_groups;
}

std::vector<InGroup> InGroupDao::getByIdGroup(int id_group){
    std::vector<InGroup> in_groups = storage.get_all<InGroup>(
                sqlite_orm::where(sqlite_orm::eq(&InGroup::getIdGroup, id_group)));

    return in_groups;
}

std::optional<InGroup> InGroupDao::getByCompositeID(int id_person, int id_group){
    std::vector<InGroup> in_groups = storage.get_all<InGroup>(
                sqlite_orm::where(sqlite_orm::eq(
                    &InGroup::getIdPerson, id_person) && sqlite_orm::eq(
                        &InGroup::getIdGroup, id_group
                    )));
    
    std::optional<InGroup> in_group = std::nullopt;
    if(in_groups.size() == 1){
        in_group = in_groups[0];
    }

    return in_group;
}

std::pair<int, int> InGroupDao::save(InGroup in_group){
    PersonDao person_dao;
    GroupDao group_dao;

    if(in_group.getIdGroup() <= 0 || in_group.getIdPerson() <= 0){
        throw ModelFormatException("Invalid ID in InGroup instance: Value cannot be zero or negative.");
    }

    if(!person_dao.exists(in_group.getIdPerson())){
        throw IdNotFoundException("Error: Non-existent Person ID in InGroup instance.");
    }
    if(!group_dao.exists(in_group.getIdGroup())){
        throw IdNotFoundException("Error: Non-existent Group ID in InGroup instance.");
    }

    storage.insert(in_group);
    std::pair<int, int> id_pair(in_group.getIdPerson(), in_group.getIdGroup());

    return id_pair;
}

void InGroupDao::deleteByIdPerson(int id_person){
    if(!existsByIdPerson(id_person)){
        throw IdNotFoundException("Error: Non-existent person to delete in InGroupsTable.");
    }

    storage.remove_all<InGroup>(sqlite_orm::where(
        sqlite_orm::eq(&InGroup::getIdPerson, id_person)));
}

void InGroupDao::deleteByIdGroup(int id_group){
    if(!existsByIdGroup(id_group)){
        throw IdNotFoundException("Error: Non-existent group to delete in InGroupsTable.");
    }

    storage.remove_all<InGroup>(sqlite_orm::where(
        sqlite_orm::eq(&InGroup::getIdGroup, id_group)));
}

void InGroupDao::deleteByCompositeId(int id_person, int id_group){
    if(!existsComposite(id_person, id_group)){
        throw IdNotFoundException("Error: Non-existent person in group.");
    }

    storage.remove_all<InGroup>(sqlite_orm::where(sqlite_orm::eq(
                    &InGroup::getIdPerson, id_person) && sqlite_orm::eq(
                        &InGroup::getIdGroup, id_group
                    )));
}

void InGroupDao::update(int id_person, int id_group, InGroup in_group){
    deleteByCompositeId(id_person, id_group);

    in_group.setIdGroup(id_group);
    in_group.setIdPerson(id_person);
    save(in_group);
}

bool InGroupDao::existsByIdPerson(int id_person){
    std::vector<InGroup> in_groups = storage.get_all<InGroup>(
                sqlite_orm::where(sqlite_orm::eq(&InGroup::getIdPerson, id_person)));
    
    return in_groups.size() >= 1;
}

bool InGroupDao::existsByIdGroup(int id_group){
    std::vector<InGroup> in_groups = storage.get_all<InGroup>(
                sqlite_orm::where(sqlite_orm::eq(&InGroup::getIdGroup, id_group)));
    
    return in_groups.size() >= 1;
}

bool InGroupDao::existsComposite(int id_person, int id_group){
    std::vector<InGroup> in_groups = storage.get_all<InGroup>(
                sqlite_orm::where(sqlite_orm::eq(
                    &InGroup::getIdPerson, id_person) && sqlite_orm::eq(
                        &InGroup::getIdGroup, id_group
                    )));
    
    return in_groups.size() == 1;
}
