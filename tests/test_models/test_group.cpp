#include "../../include/models/group.hpp"
#include "../../include/utils/time_utils.hpp"
#include "../../include/utils/string_utils.hpp"
#include <gtest/gtest.h>
#include <format>
#include <string>

TEST(TestGroup, test_default_values){
  Group group;
  std::string current_date = time_utils::get_current_date();

  ASSERT_EQ(group.getName(), "Unknown")
    <<"Default value for group name must be 'Unknown'.";
  ASSERT_EQ(group.getStartDate(), current_date)
    <<"Default value for start_date must be the current date.";
  ASSERT_EQ(group.getEndDate(), current_date)
    <<"Default value for end_date must be the current date.";
}

TEST(TestGroup, test_set_id){
  Group group;

  try{
    group.setIdGroup(-1);
    FAIL()<<"Group id can' t be negative.";
  }catch(std::invalid_argument){}

  try{
    group.setIdGroup(0);
    FAIL()<<"Group id can' t be zero.";
  }catch(std::invalid_argument){}
}

TEST(TestGroup, test_set_name){
  Group group;

  group.setName("      ");
  ASSERT_EQ(group.getName(), "Unknown") 
    <<"Name can't be empty, it should be 'Unknown' by default.";

  group.setName("");
  ASSERT_EQ(group.getName(), "Unknown") 
    <<"Name can't be empty, it should be 'Unknown' by default.";

  group.setName(" \t\n\ra            ");
  ASSERT_EQ(group.getName(), "a") 
    <<"Extreme spaces were not deleted.";
}

TEST(TestGroup, test_start_date){
  Group group;
  
  try{
    group.setStartDate("68768-321-321");
    FAIL() << "An invalid format for the date was accepted.";
  }catch(std::invalid_argument){}

  try{
    group.setStartDate("\t\t\t\n");
    FAIL() << "Date can't be empty or full of blank spaces.";
  }catch(std::invalid_argument){}

  int year = time_utils::get_current_year()+1;
  std::string date = std::format("{}-12-12", year);

  try{
    group.setStartDate(date);
    FAIL() << "Date can't be a date greater than current date.";
  }catch(std::invalid_argument){}

}

TEST(TestGroup, test_end_date){
  Group group;
  
  try{
    group.setEndDate("68768-321-321");
    FAIL() << "An invalid format for the date was accepted.";
  }catch(std::invalid_argument){}

  try{
    group.setEndDate("\t\t\t\n");
    FAIL() << "Date can't be empty or full of blank spaces.";
  }catch(std::invalid_argument){}

  int year = time_utils::get_current_year()+1;
  std::string date = std::format("{}-12-12", year);

  try{
    group.setEndDate(date);
    FAIL() << "Date can't be a date greater than current date.";
  }catch(std::invalid_argument){}
}