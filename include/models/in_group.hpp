#ifndef IN_GROUP_HPP
#define IN_GROUP_HPP

#include<stdexcept>

class InGroup {
    int id_person = 0;
    int id_group = 0;
public:
    InGroup() = default;
    InGroup(int _id_person, int _id_group);

    int getIdPerson() const;
    int getIdGroup() const;
    void setIdPerson(int id);
    void setIdGroup(int id);
};

#endif