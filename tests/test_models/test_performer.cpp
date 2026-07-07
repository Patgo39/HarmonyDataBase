#include "../../include/models/performer.hpp"
#include "../../include/utils/string_utils.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(TestPerformer, test_default_values) {
  Performer performer;

  ASSERT_EQ(performer.getIdPerformer(), 0)
    << "Default value for id_performer must be 0.";
    
  ASSERT_EQ(performer.getIdType(), 3)
    << "Default value for id_type must be 3.";

  ASSERT_EQ(performer.getName(), "Unknown")
    << "Default value for performer name must be 'Unknown'.";
}

TEST(TestPerformer, test_set_id_performer) {
  Performer performer;

  try {
    performer.setIdPerformer(-1);
    FAIL() << "An invalid negative id was setted and Performer did not throw an invalid_argument.";
  } catch (const std::invalid_argument&) {}

  try {
    performer.setIdPerformer(0);
    FAIL() << "An id of zero was setted and Performer did not throw an invalid_argument.";
  } catch (const std::invalid_argument&) {}

  performer.setIdPerformer(42);
  ASSERT_EQ(performer.getIdPerformer(), 42)
    << "The id was not updated correctly with a valid value.";
}

TEST(TestPerformer, test_set_id_type) {
  Performer performer;

  try {
    performer.setIdType(-5);
    FAIL() << "An invalid negative id_type was setted and Performer did not throw an invalid_argument.";
  } catch (const std::invalid_argument&) {}

  try {
    performer.setIdType(0);
    FAIL() << "An id_type of zero was setted and Performer did not throw an invalid_argument.";
  } catch (const std::invalid_argument&) {}

  performer.setIdType(10);
  ASSERT_EQ(performer.getIdType(), 10)
    << "The id_type was not updated correctly with a valid value.";
}

TEST(TestPerformer, test_set_name) {
  Performer performer;

  // Caso: Solo espacios en blanco
  performer.setName("      ");
  ASSERT_EQ(performer.getName(), "Unknown") 
    << "Name can't be empty, it should be 'Unknown' by default.";

  performer.setName("");
  ASSERT_EQ(performer.getName(), "Unknown") 
    << "Name can't be empty, it should be 'Unknown' by default.";

  performer.setName(" \t\n\rMichael Jackson            ");
  ASSERT_EQ(performer.getName(), "Michael Jackson") 
    << "Extreme spaces or tabs were not deleted correctly.";
}