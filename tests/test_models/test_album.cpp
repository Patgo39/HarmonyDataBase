#include "../../include/models/album.hpp"
#include "../../include/utils/time_utils.hpp"
#include <gtest/gtest.h>

// Prueba que todos los valores por defecto sean los adecuados.
TEST(TestAlbum, test_default_values){
  Album album;

  ASSERT_EQ(album.getName(), "Unknown")
    <<"Default value for album name must be 'Unknown'.";
  ASSERT_EQ(album.getPath(), "Unknown")
    <<"Default value for album name must be 'Unknown'.";
  ASSERT_EQ(album.getYear(), time_utils::get_current_year())
    <<"Default value for album name must be 'Unknown'.";
}

// Verifica que el id no sea negativo
TEST(TestAlbum, test_set_id_album){

  Album album;

  try{
    album.setIdAlbum(-1);
    FAIL() << "An invalid id was setted and Album did not threw an invalid argument error.";
  }catch(std::invalid_argument){}

  album.setIdAlbum(5);
  ASSERT_EQ(album.getIdAlbum(), 5);
}

// Se prueba la eliminación de espacios y que no se permita espacios
TEST(TestAlbum, test_set_name){
  Album album;
  album.setName("      ");

  ASSERT_EQ(album.getName(), "Unknown") 
    <<"Name can't be empty, it should be 'Unknown' by default.";

  album.setName("");
  ASSERT_EQ(album.getName(), "Unknown") 
    <<"Name can't be empty, it should be 'Unknown' by default.";

  album.setName(" \t\n\ra            ");
  ASSERT_EQ(album.getName(), "a") 
    <<"Extreme spaces were not deleted.";
}

TEST(TestAlbum, test_set_path){
  Album album;
  album.setPath("      ");

  ASSERT_EQ(album.getPath(), "Unknown") 
    <<"Path can't be empty, it should be 'Unknown' by default.";

  album.setPath(" \t\n\ra            ");
  ASSERT_EQ(album.getPath(), "a") 
    <<"Extreme spaces were not deleted.";
}

TEST(TestAlbum, test_set_year){
  int current_year = time_utils::get_current_year();
  Album album;
  
  try{
    album.setYear(999);
    FAIL() << "Album must not accept a year less than 1000.";
  }catch(std::invalid_argument){}

  try{
    album.setYear(current_year+1);
    FAIL() << "Album must not accept a year greater than "<<current_year<<".";
  }catch(std::invalid_argument){}
}
