#include "../../include/models/in_group.hpp"


InGroup::InGroup(int _id_person, int _id_group): 
    id_person(_id_person), 
    id_group(_id_group) {}

int InGroup::getIdPerson() const{
    return id_person;
}

int InGroup::getIdGroup() const{
    return id_group;
}

void InGroup::setIdPerson(int id){
    if(id<= 0){
        throw std::invalid_argument("Id can't be zero or negative.");
    }

    id_person = id;
}

void InGroup::setIdGroup(int id){
    if(id<= 0){
        throw std::invalid_argument("Id can't be zero or negative.");
    }

    id_group = id;
}