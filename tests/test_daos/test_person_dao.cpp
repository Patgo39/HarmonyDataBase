#include "../../include/daos/person_dao.hpp"
#include "../../include/exceptions/id_not_found_exception.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <optional>
#include <vector>

class TestPersonDao : public testing::Test {

protected:
  std::unique_ptr<PersonDao> dao_ptr;
  Person person;
  int id_person = -1;

  void SetUp() override {
    DatabaseConectionManager &db = DatabaseConectionManager::getInstance();
    db.setDatabaseFolderPath(":memory:");
    db.createAndStartDatabase();

    dao_ptr = std::make_unique<PersonDao>();
    
    person.setStageName("Dio");
    person.setRealName("Ronnie James Padavona");
    person.setBirthDate("1942-07-10");
    person.setDeathDate("2010-05-16");
    id_person = dao_ptr->save(person);
  }
};

TEST_F(TestPersonDao, test_get_by_id) {
  std::optional<Person> queried_person = dao_ptr->getByID(id_person);

  ASSERT_TRUE(queried_person.has_value()) << "Person is nullopt.";

  if (queried_person.has_value()) {
    ASSERT_EQ("Dio", queried_person.value().getStageName())
        << "Saved Person stage_name is not the expected one.";
    ASSERT_EQ("Ronnie James Padavona", queried_person.value().getRealName())
        << "Saved Person real_name is not the expected one.";
    ASSERT_EQ("1942-07-10", queried_person.value().getBirthDate())
        << "Saved Person birth_date is not the expected one.";
    ASSERT_EQ("2010-05-16", queried_person.value().getDeathDate())
        << "Saved Person death_date is not the expected one.";
  }
}

TEST_F(TestPersonDao, test_find_all) {
  std::vector<Person> persons_vector = dao_ptr->findAll();

  ASSERT_EQ(persons_vector.size(), 1) 
    << "The persons in the database could not be retrieved.";
  ASSERT_EQ(id_person, persons_vector[0].getIdPerson())
        << "Saved Person id is not the expected one.";
}

TEST_F(TestPersonDao, test_update) {
  person.setStageName("Ozzy Osbourne");
  person.setRealName("John Michael Osbourne");
  person.setBirthDate("1948-12-03");
  person.setDeathDate("1948-12-03"); 

  dao_ptr->update(id_person, person);

  std::optional<Person> queried_person = dao_ptr->getByID(id_person);

  ASSERT_TRUE(queried_person.has_value()) << "Person is nullopt.";
  ASSERT_EQ(1, dao_ptr->findAll().size()) 
    << "The person was not updated; instead a new person was inserted.";

  if (queried_person.has_value()) {
    ASSERT_EQ("Ozzy Osbourne", queried_person.value().getStageName())
        << "Updated Person stage_name is not the expected one.";
    ASSERT_EQ("John Michael Osbourne", queried_person.value().getRealName())
        << "Updated Person real_name is not the expected one.";
    ASSERT_EQ("1948-12-03", queried_person.value().getBirthDate())
        << "Updated Person birth_date is not the expected one.";
  }
}

TEST_F(TestPersonDao, test_exists) {
  ASSERT_TRUE(dao_ptr->exists(id_person))
    << "The person does not exist.";
  ASSERT_FALSE(dao_ptr->exists(-1))
    << "exists function threw a false positive.";
}

TEST_F(TestPersonDao, test_delete) {
  try {
    dao_ptr->deleteById(-5);
    FAIL() << "IdNotFoundException was not thrown.";
  } catch (const IdNotFoundException&) {}

  dao_ptr->deleteById(id_person);

  ASSERT_EQ(0, dao_ptr->findAll().size())
    << "There are more persons in the database than expected after deletion.";
  ASSERT_FALSE(dao_ptr->exists(id_person))
    << "Person was not correctly deleted.";
}

TEST_F(TestPersonDao, test_update_non_existent) {
  Person fake_person;
  fake_person.setStageName("Lemmy");
  
  try {
    dao_ptr->update(-999, fake_person);
    FAIL() << "Expected IdNotFoundException when updating a non-existent Person.";
  } catch (const IdNotFoundException&) {}
}