#ifndef TYPE_DAO_HPP
#define TYPE_DAO_HPP

#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../models/type.hpp"
#include "dao_interface.hpp"
#include <sqlite_orm/sqlite_orm.h>

class TypeDao : public DaoInterface<Type> {
  std::shared_ptr<harmony_storage> storage;

public:
  TypeDao();

  std::vector<Type> findAll() override;
  std::optional<Type> getByID(int id_type) override;
  int save(Type type) override;
  void deleteById(int id_type) override;
  void update(int id_type, Type type) override;
  bool exists(int id_type) override;
};

#endif