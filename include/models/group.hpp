#ifndef GROUP_HPP
#define GROUP_HPP

#include <string>
#include <stdexcept>
#include <regex>
#include <iomanip>
#include <sstream>
#include <ctime>

class Group {
    int id_group;
    std::string name;
    std::string start_date;
    std::string end_date;

    void validateDate(const std::string &date) const;
    std::string getCurrentDate() const;

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