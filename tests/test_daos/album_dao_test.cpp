#include "../../include/daos/album_dao.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <sqlite3.h>
#include <string>

class AlbumDaoTest : public testing::Test {

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

  void TearDown() override {}
};

TEST_F(AlbumDaoTest, get_by_id) {
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

TEST_F(AlbumDaoTest, test_findAll){
  std::vector<Album> album_vector = dao_ptr->findAll();

  ASSERT_EQ(album_vector.size(), 1) 
    << "The albums in the database could not be retrieved.";
  ASSERT_EQ(id_album, album_vector[0].getIdAlbum())
        << "Saved Album id is not the expected one.";

}

TEST_F(AlbumDaoTest, test_update){
  Album album2;
  album2.setIdAlbum(5);
  album2.setName("The dark side of the moon");
  album2.setPath(":Memory:/Path/2");
  album2.setYear(1973);

  dao_ptr->update(id_album, album2);

  std::optional<Album> queried_album = dao_ptr->getByID(id_album);

  ASSERT_EQ(true, queried_album.has_value()) << "Album is nullopt.";
  ASSERT_EQ(1, dao_ptr->findAll().size()) << "The albums was not updated; instead a new album was inserted.";

  if (queried_album.has_value()) {
    ASSERT_EQ("The dark side of the moon", queried_album.value().getName())
        << "Updated Album name is not the expected one.";
    ASSERT_EQ(":Memory:/Path/2", queried_album.value().getPath())
        << "Updated Album path is not the expected one.";
    ASSERT_EQ(1973, queried_album.value().getYear())
        << "Updated Album year is not the expected one.";
  }

}
