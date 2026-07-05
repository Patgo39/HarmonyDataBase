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
}

#endif