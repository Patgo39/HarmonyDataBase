#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

namespace str_utils{

  bool is_white_spaces(const std::string &s);
  std::string delete_extreme_whitespaces(const std::string &s);
  void convert_string_to_lowercase(std::string &s);
  void collapse_internal_whitespaces(std::string &s);
  std::string apply_name_format_to_string(const std::string &s);
}

#endif