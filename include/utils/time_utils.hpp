#include <chrono>
#include <string>
#include <regex>
#include <iomanip>
#include <sstream>
#include <ctime>

namespace time_utils{
  int get_current_year();
  bool is_year_valid(int year);
  std::string get_current_date();
  bool is_date_string_valid(const std::string &date);
}