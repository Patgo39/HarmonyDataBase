#ifndef TYPE_DAO_HPP
#define TYPE_DAO_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../models/type.hpp"
#include "dao_interface.hpp"

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