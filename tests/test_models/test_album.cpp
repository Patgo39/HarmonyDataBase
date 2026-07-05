#include "../../include/models/album.hpp"
#include <gtest/gtest.h>

TEST(TestAlbum, test_default_values){
  Album album;
  auto now = std::chrono::system_clock::now();
  std::time_t time_c = std::chrono::system_clock::to_time_t(now);
  std::tm *local_date = std::localtime(&time_c);
  int current_year = local_date->tm_year + 1900;

  ASSERT_EQ(album.getName(), "Unknown")
    <<"Default value for album name must be 'Unknown'.";
  ASSERT_EQ(album.getPath(), "Unknown")
    <<"Default value for album name must be 'Unknown'.";
  ASSERT_EQ(album.getYear(), current_year)
    <<"Default value for album name must be 'Unknown'.";
}

TEST(TestAlbum, test_set_id_album){

  Album album;

  try{
    album.setIdAlbum(-1);
    FAIL() << "An invalid id was setted and Album did not threw an invalid argument error.";
  }catch(std::invalid_argument){}

  album.setIdAlbum(5);
  ASSERT_EQ(album.getIdAlbum(), 5);
}

TEST(TestAlbum, test_set_name){
  Album album;
  album.setName("      ");

  ASSERT_EQ(album.getName(), "Unknown") 
    <<"Name can't be empty, it should be 'Unknown' by default.";
}

