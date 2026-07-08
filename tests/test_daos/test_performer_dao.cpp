#include "../../include/daos/performer_dao.hpp"
#include "../../include/exceptions/id_not_found_exception.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <optional>
#include <vector>

class TestPerformerDao : public testing::Test {

protected:
  std::unique_ptr<PerformerDao> dao_ptr;
  Performer performer;
  int id_performer = -1;

  void SetUp() override {
    DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
    db.setDatabaseFolderPath(":memory:");
    db.createAndStartDatabase();

    dao_ptr = std::make_unique<PerformerDao>();
    
    performer.setName("Michael Jackson");
    performer.setIdType(1); // 1 = Person

    id_performer = dao_ptr->save(performer);
  }
};

TEST_F(TestPerformerDao, test_get_by_id) {
  std::optional<Performer> queried_performer = dao_ptr->getByID(id_performer);

  ASSERT_TRUE(queried_performer.has_value()) << "Performer is nullopt.";

  if (queried_performer.has_value()) {
    ASSERT_EQ("Michael Jackson", queried_performer.value().getName())
        << "Saved Performer name is not the expected one.";
    ASSERT_EQ(1, queried_performer.value().getIdType())
        << "Saved Performer id_type is not the expected one.";
  }
}

TEST_F(TestPerformerDao, test_find_all) {
  std::vector<Performer> performers_vector = dao_ptr->findAll();

  ASSERT_EQ(performers_vector.size(), 1) 
    << "The performers in the database could not be retrieved.";
  ASSERT_EQ(id_performer, performers_vector[0].getIdPerformer())
        << "Saved Performer id is not the expected one.";
}

TEST_F(TestPerformerDao, test_update) {
  performer.setName("Daft Punk");
  performer.setIdType(2); // 2 = Group 

  dao_ptr->update(id_performer, performer);

  std::optional<Performer> queried_performer = dao_ptr->getByID(id_performer);

  ASSERT_TRUE(queried_performer.has_value()) << "Performer is nullopt.";
  ASSERT_EQ(1, dao_ptr->findAll().size()) 
    << "The performer was not updated; instead a new performer was inserted.";

  if (queried_performer.has_value()) {
    ASSERT_EQ("Daft Punk", queried_performer.value().getName())
        << "Updated Performer name is not the expected one.";
    ASSERT_EQ(2, queried_performer.value().getIdType())
        << "Updated Performer id_type is not the expected one.";
  }
}

TEST_F(TestPerformerDao, test_exists) {
  ASSERT_TRUE(dao_ptr->exists(id_performer))
    << "The performer does not exist.";
  ASSERT_FALSE(dao_ptr->exists(-1))
    << "exists function threw a false positive.";
}

TEST_F(TestPerformerDao, test_delete) {
  try {
    dao_ptr->deleteById(-5);
    FAIL() << "IdNotFoundException was not thrown.";
  } catch (const IdNotFoundException&) {}

  dao_ptr->deleteById(id_performer);

  ASSERT_EQ(0, dao_ptr->findAll().size())
    << "There are more performers in the database than expected after deletion.";
  ASSERT_FALSE(dao_ptr->exists(id_performer))
    << "Performer was not correctly deleted.";
}

TEST_F(TestPerformerDao, test_update_non_existent) {
  Performer fake_performer;
  fake_performer.setName("Ghost");
  
  try {
    dao_ptr->update(-999, fake_performer);
    FAIL() << "Expected IdNotFoundException when updating a non-existent Performer.";
  } catch (const IdNotFoundException&) {}
}