#include "../../include/utils/string_utils.hpp"

namespace str_utils{
  const std::string whitespaces = " \t\n\r\f\v";

  bool is_white_spaces(const std::string &s){
    size_t start = s.find_first_not_of(whitespaces);

    return start == std::string::npos;
  }

  std::string delete_extreme_whitespaces(const std::string &s){
    size_t start = s.find_first_not_of(whitespaces);

    if(start==std::string::npos){
      return "";
    }

    size_t end = s.find_last_not_of(whitespaces);

    return s.substr(start, end-start+1);
  }

  void convert_string_to_lowercase(std::string &s){
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
      return std::tolower(c);
    });
  }

  std::string clean_string_format(const std::string &s){
    
  }
}