#include "../../include/daos/group_dao.hpp"
#include "../../include/daos/performer_dao.hpp"
#include "../../include/exceptions/id_not_found_exception.hpp"
#include "../../include/utils/time_utils.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <optional>
#include <vector>

class TestGroupDao : public testing::Test {

protected:
  std::unique_ptr<GroupDao> dao_ptr;
  std::unique_ptr<PerformerDao> performer_dao_ptr;
  Group group;
  Performer p;
  int id_group = -1;
  int id_performer = -1;

  void SetUp() override {
    DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
    db.setDatabaseFolderPath(":memory:");
    db.createAndStartDatabase();

    dao_ptr = std::make_unique<GroupDao>();
    performer_dao_ptr = std::make_unique<PerformerDao>();

    p.setName("Queen");
    p.setIntType(2); 
    id_performer = performer_dao_ptr->save(p);

    group.setIdGroup(id_performer);
    group.setName("Queen");

    id_group = dao_ptr->save(group);
  }
};

TEST_F(TestGroupDao, test_save_group) {
  try {
    dao_ptr->save(group);
    FAIL() << "Group Dao must throw a PrimaryKeyViolationException.";
  } catch (const PrimaryKeyViolationException&) {}
  
  Performer test_performer;
  test_performer.setName("Performer_Test_Group");
  test_performer.setIntType(3);
  id_performer = performer_dao_ptr->save(test_performer);

  Group test_group;
  test_group.setName("Test_Group_Name");
  test_group.setIdGroup(id_performer + 1);

  try {
    dao_ptr->save(test_group);
    FAIL() << "Group Dao must throw an IdNotFoundException when id_group does not exist in Performer's table.";
  } catch (const IdNotFoundException&) {}

  test_group.setIdGroup(id_performer);

  try {
    dao_ptr->save(test_group);
    FAIL() << "Group Dao must throw a ConstraintViolationException when performer in Performer table has not type = 2.";
  } catch (const ConstraintViolationException&) {}

  test_performer.setIntType(2);
  performer_dao_ptr->update(id_performer, test_performer);

  try {
    id_group = dao_ptr->save(test_group);
  } catch (const std::runtime_error&) {
    FAIL() << "Group Dao must not throw an exception at this stage.";
  }

  ASSERT_EQ(id_performer, id_group) << "id_performer and id_group are not equal.";
}

TEST_F(TestGroupDao, test_get_by_id) {
  std::optional<Group> queried_group = dao_ptr->getByID(id_group);

  ASSERT_TRUE(queried_group.has_value()) << "Group is nullopt.";

  if (queried_group.has_value()) {
    std::string current_date = time_utils::get_current_date();
    ASSERT_EQ("Queen", queried_group.value().getName())
        << "Saved Group name is not the expected one.";
    ASSERT_EQ(current_date, queried_group.value().getStartDate())
        << "Saved Group start_date is not the current date.";
    ASSERT_EQ(current_date, queried_group.value().getEndDate())
        << "Saved Group end_date is not the current date.";
  }
}

TEST_F(TestGroupDao, test_find_all) {
  std::vector<Group> groups_vector = dao_ptr->findAll();

  ASSERT_EQ(groups_vector.size(), 1) 
    << "The groups in the database could not be retrieved.";
  ASSERT_EQ(id_group, groups_vector[0].getIdGroup())
        << "Saved Group id is not the expected one.";
}

TEST_F(TestGroupDao, test_update) {
  group.setName("The Beatles");
  group.setStartDate("1960-01-01");
  group.setEndDate("1970-04-10"); 

  dao_ptr->update(id_group, group);

  std::optional<Group> queried_group = dao_ptr->getByID(id_group);

  ASSERT_TRUE(queried_group.has_value()) << "Group is nullopt.";
  ASSERT_EQ(1, dao_ptr->findAll().size()) 
    << "The group was not updated; instead a new group was inserted.";

  if (queried_group.has_value()) {
    ASSERT_EQ("The Beatles", queried_group.value().getName())
        << "Updated Group name is not the expected one.";
    ASSERT_EQ("1960-01-01", queried_group.value().getStartDate())
        << "Updated Group start_date is not the expected one.";
    ASSERT_EQ("1970-04-10", queried_group.value().getEndDate())
        << "Updated Group end_date is not the expected one.";
  }
}

TEST_F(TestGroupDao, test_exists) {
  ASSERT_TRUE(dao_ptr->exists(id_group))
    << "The group does not exist.";
  ASSERT_FALSE(dao_ptr->exists(-1))
    << "exists function threw a false positive.";
}

TEST_F(TestGroupDao, test_delete) {
  try {
    dao_ptr->deleteById(-5);
    FAIL() << "IdNotFoundException was not thrown.";
  } catch (const IdNotFoundException&) {}

  dao_ptr->deleteById(id_group);

  ASSERT_EQ(0, dao_ptr->findAll().size())
    << "There are more groups in the database than expected after deletion.";
  ASSERT_FALSE(dao_ptr->exists(id_group))
    << "Group was not correctly deleted.";
}

TEST_F(TestGroupDao, test_update_non_existent) {
  Group fake_group;
  fake_group.setName("Led Zeppelin");
  
  try {
    dao_ptr->update(-999, fake_group);
    FAIL() << "Expected IdNotFoundException when updating a non-existent Group.";
  } catch (const IdNotFoundException&) {}
}