#include "../../include/models/person.hpp"
#include "../../include/utils/time_utils.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(TestPerson, test_default_values) {
  Person person;
  std::string current_date = time_utils::get_current_date();

  ASSERT_EQ(person.getIdPerson(), 0)
    << "Default value for id_person must be 0.";
    
  ASSERT_EQ(person.getStageName(), "Unknown")
    << "Default value for stage_name must be 'Unknown'.";

  ASSERT_EQ(person.getRealName(), "Unknown")
    << "Default value for real_name must be 'Unknown'.";

  ASSERT_EQ(person.getBirthDate(), current_date)
    << "Default value for birth_date must be the current date.";

  ASSERT_EQ(person.getDeathDate(), current_date)
    << "Default value for death_date must be the current date.";
}

TEST(TestPerson, test_set_id_person) {
  Person person;

  try {
    person.setIdPerson(-1);
    FAIL() << "An invalid negative id was setted and Person did not throw an invalid_argument.";
  } catch (const std::invalid_argument&) {}

  try {
    person.setIdPerson(0);
    FAIL() << "An id of zero was setted and Person did not throw an invalid_argument.";
  } catch (const std::invalid_argument&) {}

  person.setIdPerson(10);
  ASSERT_EQ(person.getIdPerson(), 10)
    << "The id_person was not updated correctly with a valid value.";
}

TEST(TestPerson, test_set_stage_name) {
  Person person;

  person.setStageName("      ");
  ASSERT_EQ(person.getStageName(), "Unknown") 
    << "Stage name can't be empty, it should be 'Unknown' by default.";

  person.setStageName("");
  ASSERT_EQ(person.getStageName(), "Unknown") 
    << "Stage name can't be empty, it should be 'Unknown' by default.";

  person.setStageName(" \t\n\r  Dio            ");
  ASSERT_EQ(person.getStageName(), "Dio") 
    << "Extreme spaces or tabs were not deleted from stage name.";
}

TEST(TestPerson, test_set_real_name) {
  Person person;

  person.setRealName("      ");
  ASSERT_EQ(person.getRealName(), "Unknown") 
    << "Real name can't be empty, it should be 'Unknown' by default.";

  person.setRealName("");
  ASSERT_EQ(person.getRealName(), "Unknown") 
    << "Real name can't be empty, it should be 'Unknown' by default.";

  person.setRealName(" \t\n\r Ronnie James Padavona   ");
  ASSERT_EQ(person.getRealName(), "Ronnie James Padavona") 
    << "Extreme spaces or tabs were not deleted from real name.";
}


TEST(TestPerson, test_set_birth_date) {
  Person person;

  try {
    person.setBirthDate("invalid-date-format");
    FAIL() << "An invalid format for birth_date was accepted.";
  } catch (const std::invalid_argument&) {}

  try {
    person.setBirthDate("2004/03/21");
    FAIL() << "An invalid format with slashes for birth_date was accepted.";
  } catch (const std::invalid_argument&) {}

  person.setBirthDate("1942-07-10");
  ASSERT_EQ(person.getBirthDate(), "1942-07-10")
    << "The birth_date was not updated correctly with a valid string format.";
}

TEST(TestPerson, test_set_death_date) {
  Person person;

  try {
    person.setDeathDate("  -  -  ");
    FAIL() << "An empty/invalid format for death_date was accepted.";
  } catch (const std::invalid_argument&) {}

  try {
    person.setDeathDate("2010-13-40"); 
    FAIL() << "An invalid calendar format for death_date was accepted.";
  } catch (const std::invalid_argument&) {}

  person.setDeathDate("2010-05-16");
  ASSERT_EQ(person.getDeathDate(), "2010-05-16")
    << "The death_date was not updated correctly with a valid string format.";
}