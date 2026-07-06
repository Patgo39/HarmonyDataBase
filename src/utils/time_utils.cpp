#include "../../include/utils/time_utils.hpp"

namespace time_utils{
  int get_current_year(){
    auto now = std::chrono::system_clock::now();
    std::time_t time_c = std::chrono::system_clock::to_time_t(now);
    std::tm *local_date = std::localtime(&time_c);
    return local_date->tm_year + 1900;
  }

  bool is_year_valid(int year){
    return year >= 1000 && year <= get_current_year();
  }

  std::string get_current_date(){
    std::time_t now = std::time(nullptr);
    std::tm localTime = *std::localtime(&now);
    std::stringstream ss;
    ss << std::put_time(&localTime, "%Y-%m-%d");
    return ss.str();
  }

  bool is_date_string_valid(const std::string &date){
    static const std::regex date_pattern(
      R"(^([0-9]{4})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$)");
    
    if(!std::regex_match(date, date_pattern)) return false;
    
    int year = std::stoi(date.substr(0, 4));

    return year >= 1000 && year <= get_current_year();
  }
}