#include "../../include/daos/group_dao.hpp"
#include "../../include/utils/time_utils.hpp"
#include <gtest/gtest.h>
#include <memory>

class TestGroupDao : public testing::Test {

protected:
  std::unique_ptr<GroupDao> dao_ptr;
  Group group;
  int id_group;
  void SetUp() override {

    DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
    db.setDatabaseFolderPath(":memory:");
    db.createAndStartDatabase();

    dao_ptr = std::make_unique<GroupDao>();
    group.setName("Queen");

    id_group = dao_ptr->save(group);
  }
};

TEST_F(TestGroupDao, test_get_by_id){
  std::optional<Group> queried_group = dao_ptr->getByID(id_group);
  ASSERT_TRUE(queried_group.has_value()) <<"Queried album is nullopt.";

  Group g = queried_group.value();
  std::string current_date = time_utils::get_current_date();
  
  ASSERT_EQ(g.getName(), "Queen") << "Group name is not Queen.";
  ASSERT_EQ(g.getStartDate(), current_date) << "Group start_date is not "<<current_date<<".";
  ASSERT_EQ(g.getEndDate(), current_date) << "Group end_date is not "<<current_date<<".";
}

TEST_F(TestGroupDao, test_find_all){
  std::vector<Group> groups = dao_ptr->findAll();

  ASSERT_EQ(1,groups.size()) << "Not all the groups were found.";
  ASSERT_EQ(id_group, groups[0].getIdGroup()) << "The group's id was not the expected one.";
}

TEST_F(TestGroupDao, test_update){
  group.setName("The beatles");
  group.setStartDate("1956-03-01");
  group.setEndDate("1970-04-10");

  dao_ptr->update(id_group, group);

  std::optional<Group> queried_group = dao_ptr->getByID(id_group);

  ASSERT_TRUE(queried_group.has_value()) << "Group is nullopt";
  ASSERT_EQ(1, dao_ptr->findAll().size()) << "The group was not upadted, instead a new group was inserted.";

  Group g = queried_group.value();

  ASSERT_EQ(g.getName(), "The beatles") << "Updated group's name is not the expected one.";
  ASSERT_EQ(g.getStartDate(), "1956-03-01") << "Updated group's start_date is not the expected one.";
  ASSERT_EQ(g.getEndDate(), "1970-04-10") << "Updated groups's end_date is not the expected one.";

}

TEST_F(TestGroupDao, test_exists){
  ASSERT_EQ(true, dao_ptr->exists(id_group))
    <<"The group does not exists.";
  ASSERT_EQ(false, dao_ptr->exists(-1))
  << "exists function threw a false positive.";
}

TEST_F(TestGroupDao, test_delete){

  try{
    dao_ptr->deleteById(-5);
    ASSERT_FALSE(true)
      <<"Not IdNotFoundException threw.";
  }catch(IdNotFoundException){}

  dao_ptr->deleteById(id_group);

  ASSERT_EQ(0, dao_ptr->findAll().size())
    <<"There more albums in the database than expected in delete test.";
  ASSERT_EQ(false, dao_ptr->exists(id_group))
    <<"Group was not correctly deleted.";
}