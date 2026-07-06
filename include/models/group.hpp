#ifndef GROUP_HPP
#define GROUP_HPP

#include "../utils/time_utils.hpp"
#include "../utils/string_utils.hpp"
#include <string>
#include <stdexcept>

class Group {
    int id_group;
    std::string name;
    std::string start_date;
    std::string end_date;

public:
    Group();

    int getIdGroup() const;
    void setIdGroup(int idGroup);

    std::string getName() const;
    void setName(const std::string &name_);

    std::string getStartDate() const;
    void setStartDate(const std::string &startDate_);

    std::string getEndDate() const;
    void setEndDate(const std::string &endDate_);
};

#endif