#include "../../include/daos/album_dao.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

class TestAlbumDao : public testing::Test {

protected:
  std::unique_ptr<AlbumDao> dao_ptr = std::make_unique<AlbumDao>();
  Album album;
  int id_album = -1;

  void SetUp() override {

    DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
    db.setDatabaseFolderPath(":memory:");
    db.createAndStartDatabase();

    album.setName("Thriller");
    album.setPath(":Memory:/Path");
    album.setYear(1982);


    dao_ptr = std::make_unique<AlbumDao>();
    id_album = dao_ptr->save(album);
  }
};

TEST_F(TestAlbumDao, test_save_duplicates){
  Album a;
  a.setName("   \t   thRíLler  \n");
  int id_a = 0;
  id_a = dao_ptr->save(a);

  ASSERT_EQ(1, dao_ptr->findAll().size()) <<"AlbumDao inserted another registed instead of ignoring the repeated one.";
  ASSERT_EQ(id_album, id_a) <<"id_album and id_a are not equal.";
}

TEST_F(TestAlbumDao, test_get_by_id) {
  std::optional<Album> queried_album = dao_ptr->getByID(id_album);

  ASSERT_EQ(true, queried_album.has_value()) << "Album is nullopt.";

  if (queried_album.has_value()) {
    ASSERT_EQ("Thriller", queried_album.value().getName())
        << "Saved Album name is not the expected one.";
    ASSERT_EQ(":Memory:/Path", queried_album.value().getPath())
        << "Saved Album path is not the expected one.";
    ASSERT_EQ(1982, queried_album.value().getYear())
        << "Saved Album year is not the expected one.";
  }
}

TEST_F(TestAlbumDao, test_findAll){
  std::vector<Album> album_vector = dao_ptr->findAll();

  ASSERT_EQ(album_vector.size(), 1) 
    << "The albums in the database could not be retrieved.";
  ASSERT_EQ(id_album, album_vector[0].getIdAlbum())
        << "Saved Album id is not the expected one.";

}

TEST_F(TestAlbumDao, test_update){
  album.setIdAlbum(5);
  album.setName("The dark side of the moon");
  album.setPath(":Memory:/Path/2");
  album.setYear(1973);

  dao_ptr->update(id_album, album);

  std::optional<Album> queried_album = dao_ptr->getByID(id_album);

  ASSERT_TRUE(queried_album.has_value()) << "Album is nullopt.";
  ASSERT_EQ(1, dao_ptr->findAll().size()) << "The albums was not updated; instead a new album was inserted.";

  if (queried_album.has_value()) {
    ASSERT_EQ("The Dark Side Of The Moon", queried_album.value().getName())
        << "Updated Album name is not the expected one.";
    ASSERT_EQ(":Memory:/Path/2", queried_album.value().getPath())
        << "Updated Album path is not the expected one.";
    ASSERT_EQ(1973, queried_album.value().getYear())
        << "Updated Album year is not the expected one.";
  }

}

TEST_F(TestAlbumDao, test_exists){
  ASSERT_EQ(true, dao_ptr->exists(id_album))
    <<"The album does not exists.";
  ASSERT_EQ(false, dao_ptr->exists(-1))
  << "exists function threw a false positive.";
}

TEST_F(TestAlbumDao, test_delete){

  try{
    dao_ptr->deleteById(-5);
    ASSERT_FALSE(true)
      <<"Not IdNotFoundException threw.";
  }catch(IdNotFoundException){}

  dao_ptr->deleteById(id_album);

  ASSERT_EQ(0, dao_ptr->findAll().size())
    <<"There more albums in the database than expected in delete test.";
  ASSERT_EQ(false, dao_ptr->exists(id_album))
    <<"Album was not correctly deleted.";
}