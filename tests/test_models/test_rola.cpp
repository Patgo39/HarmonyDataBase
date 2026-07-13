#include "../../include/models/rola.hpp"
#include "../../include/utils/time_utils.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(TestRola, test_default_values) {
  Rola rola;

  ASSERT_EQ(rola.getIdRola(), 0) << "Default value for id_rola must be 0.";
  ASSERT_EQ(rola.getIdPerformer(), 0) << "Default value for id_performer must be 0.";
  ASSERT_EQ(rola.getIdAlbum(), 0) << "Default value for id_album must be 0.";
  ASSERT_EQ(rola.getPath(), "Unknown") << "Default value for path must be 'Unknown'.";
  ASSERT_EQ(rola.getTitle(), "Unknown") << "Default value for title must be 'Unknown'.";
  ASSERT_EQ(rola.getTrack(), 0) << "Default value for track must be 0.";
  ASSERT_EQ(rola.getYear(), time_utils::get_current_year()) << "Default value for year must be the current year.";
  ASSERT_EQ(rola.getGenre(), "Unknown") << "Default value for genre must be 'Unknown'.";
}

TEST(TestRola, test_set_ids) {
  Rola rola;

  try {
    rola.setIdRola(0);
    FAIL() << "An id_rola of zero was accepted.";
  } catch (const std::invalid_argument&) {}
  try {
    rola.setIdRola(-5);
    FAIL() << "A negative id_rola was accepted.";
  } catch (const std::invalid_argument&) {}

  try {
    rola.setIdPerformer(0);
    FAIL() << "An id_performer of zero was accepted.";
  } catch (const std::invalid_argument&) {}
  try {
    rola.setIdPerformer(-10);
    FAIL() << "A negative id_performer was accepted.";
  } catch (const std::invalid_argument&) {}

  try {
    rola.setIdAlbum(0);
  } catch (const std::invalid_argument&) {}
  try {
    rola.setIdAlbum(-1);
    FAIL() << "A negative id_album was accepted.";
  } catch (const std::invalid_argument&) {}

  rola.setIdRola(1);
  rola.setIdPerformer(2);
  rola.setIdAlbum(3);
  ASSERT_EQ(rola.getIdRola(), 1);
  ASSERT_EQ(rola.getIdPerformer(), 2);
  ASSERT_EQ(rola.getIdAlbum(), 3);
}

TEST(TestRola, test_set_title) {
  Rola rola;

  rola.setTitle("      ");
  ASSERT_EQ(rola.getTitle(), "Unknown") << "Title can't be empty, it should be 'Unknown'.";

  rola.setTitle("");
  ASSERT_EQ(rola.getTitle(), "Unknown") << "Title can't be empty, it should be 'Unknown'.";

  rola.setTitle(" \t\n\r mAsTer Óf pUppets   ");
  ASSERT_EQ(rola.getTitle(), "Master Of Puppets") << "Rola's name was not correctly normalized.";
}

TEST(TestRola, test_set_path) {
  Rola rola;

  rola.setPath("   ");
  ASSERT_EQ(rola.getPath(), "Unknown") << "Path can't be empty, it should be 'Unknown'.";

  rola.setPath("/music/rock/song.mp3");
  ASSERT_EQ(rola.getPath(), "/music/rock/song.mp3");
}

TEST(TestRola, test_set_genre) {
  Rola rola;

  rola.setGenre("\n\r  ");
  ASSERT_EQ(rola.getGenre(), "Unknown") << "Genre can't be empty, it should be 'Unknown'.";

  rola.setGenre("  Heavy Metal   ");
  ASSERT_EQ(rola.getGenre(), "Heavy Metal") << "Extreme spaces or tabs were not deleted from genre.";
}

TEST(TestRola, test_set_track) {
  Rola rola;

  try {
    rola.setTrack(-1);
    FAIL() << "A negative track number was accepted.";
  } catch (const std::invalid_argument&) {}

  rola.setTrack(7);
  ASSERT_EQ(rola.getTrack(), 7);
}

TEST(TestRola, test_set_year) {
  Rola rola;

  try {
    rola.setYear(99999); 
    FAIL() << "An invalid year was accepted by the model.";
  } catch (const std::invalid_argument&) {}

  rola.setYear(2026);
  ASSERT_EQ(rola.getYear(), 2026);
}