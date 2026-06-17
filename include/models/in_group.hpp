#ifndef IN_GROUP_HPP
#define IN_GROUP_HPP

class InGroup {
public:
    int id_person = 0;
    int id_group = 0;

    InGroup() = default;
    InGroup(int _id_person, int _id_group);
};

#endif