#include "../../include/models/group.hpp"

// Método auxiliar para obtener la fecha del sistema en formato YYYY-MM-DD
std::string Group::getCurrentDate() const {
    std::time_t now = std::time(nullptr);
    std::tm localTime = *std::localtime(&now);
    std::stringstream ss;
    ss << std::put_time(&localTime, "%Y-%m-%d");
    return ss.str();
}

// Método auxiliar para validar meses (01-12) y días (01-31)
void Group::validateDate(const std::string &date) const {
    static const std::regex date_pattern(R"(^([0-9]{4})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$)");
    
    if (!std::regex_match(date, date_pattern)) {
        throw std::invalid_argument("Year has an invalid format. Must be YYYY-MM-DD with valid month and day.");
    }
}

Group::Group() : 
    id_group(0),
    name("Unknown")
{
    std::string current = getCurrentDate();
    start_date = current;
    end_date = current;
}

int Group::getIdGroup() const {
    return id_group;
}

void Group::setIdGroup(int idGroup) {
    if(idGroup <= 0){
        throw std::invalid_argument("Id can't be zero or negative.");
    }
    id_group = idGroup;
}

std::string Group::getName() const {
    return name;
}

void Group::setName(const std::string &name_) {
    if (name_.empty()) {
        name = "Unknown";
    } else {
        name = name_;
    }
}

std::string Group::getStartDate() const {
    return start_date;
}

void Group::setStartDate(const std::string &startDate_) {
    validateDate(startDate_);
    start_date = startDate_;
}

std::string Group::getEndDate() const {
    return end_date;
}

void Group::setEndDate(const std::string &endDate_) {
    validateDate(endDate_);
    end_date = endDate_;
}