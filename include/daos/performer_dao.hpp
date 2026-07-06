#ifndef PERFORMER_DAO_HPP
#define PERFORMER_DAO_HPP

#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "../models/performer.hpp"
#include "../models/type.hpp"
#include "dao_interface.hpp"

class PerformerDao : public DaoInterface<Performer> {
  std::shared_ptr<harmony_storage> storage;

public:
  PerformerDao();

  std::vector<Performer> findAll() override;
  std::optional<Performer> getByID(int id_performer) override;
  int save(Performer performer) override;
  void deleteById(int id_performer) override;
  void update(int id_performer, Performer performer) override;
  bool exists(int id_performer) override;
};

#endif