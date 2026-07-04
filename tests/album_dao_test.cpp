#include "../include/daos/album_dao.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <sqlite3.h>
#include <string>

class AlbumDaoTest : public testing::Test {

protected:
  std::unique_ptr<AlbumDao> dao_ptr = std::make_unique<AlbumDao>();
  Album album;

  void SetUp() override {

    DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
    db.setDatabaseFolderPath(":memory:");
    db.createAndStartDatabase();

    album.setName("Thriller");
    album.setPath(":Memory:/Path");
    album.setYear(1982);


    dao_ptr = std::make_unique<AlbumDao>();
  }

  void TearDown() override {}
};

TEST_F(AlbumDaoTest, test_save_get) {
  int id = dao_ptr->save(album);

  std::optional<Album> queried_album = dao_ptr->getByID(id);

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