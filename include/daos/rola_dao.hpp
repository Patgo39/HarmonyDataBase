#ifndef ROLA_DAO_HPP
#define ROLA_DAO_HPP

#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../models/album.hpp"
#include "../models/performer.hpp"
#include "../models/rola.hpp"
#include "dao_interface.hpp"
#include <sqlite_orm/sqlite_orm.h>

class RolaDao : public DaoInterface<Rola> {
  std::shared_ptr<harmony_storage> storage;

public:
  RolaDao();

  std::vector<Rola> findAll() override;
  std::optional<Rola> getByID(int id_rola) override;
  int save(Rola rola) override;
  void deleteById(int id_rola) override;
  void update(int id_rola, Rola rola) override;
  bool exists(int id_rola) override;
};

#endif