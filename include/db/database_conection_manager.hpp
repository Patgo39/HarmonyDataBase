#ifndef DATABASE_CONECTION_MANAGER_HPP
#define DATABASE_CONECTION_MANAGER_HPP

// Suprime las advertencias de funciones deprecadas en la biblioteca sqlite_orm
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include "../models/album.hpp"
#include "../models/group.hpp"
#include "../models/in_group.hpp"
#include "../models/performer.hpp"
#include "../models/person.hpp"
#include "../models/rola.hpp"
#include <cstring>
#include <filesystem>
#include <iostream>
#include <memory>
#include <optional>
#include <sqlite3.h>
#include <sqlite_orm/sqlite_orm.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

inline auto make_harmony_storage(const std::string &path) {
  return sqlite_orm::make_storage("",
      // Performer
      sqlite_orm::make_table(
          "performers",
          sqlite_orm::make_column("id_performer", &Performer::getIdPerformer,
                                  &Performer::setIdPerformer,
                                  sqlite_orm::primary_key().autoincrement()),
          sqlite_orm::make_column("id_type", &Performer::getIntType,
                                  &Performer::setIntType),
          sqlite_orm::make_column("name", &Performer::getName,
                                  &Performer::setName)),
      // Albums
      sqlite_orm::make_table(
          "albums",
          sqlite_orm::make_column("id_album", &Album::getIdAlbum,
                                  &Album::setIdAlbum,
                                  sqlite_orm::primary_key().autoincrement()),
          sqlite_orm::make_column("path", &Album::getPath, &Album::setPath),
          sqlite_orm::make_column("name", &Album::setName, &Album::getName),
          sqlite_orm::make_column("year", &Album::setYear, &Album::getYear)),
      // Groups
      sqlite_orm::make_table(
          "groups",
          sqlite_orm::make_column("id_group", &Group::setIdGroup,
                                  &Group::getIdGroup,
                                  sqlite_orm::primary_key()),
          sqlite_orm::make_column("name", &Group::getName, &Group::setName),
          sqlite_orm::make_column("start_date", &Group::setStartDate,
                                  &Group::getStartDate),
          sqlite_orm::make_column("end_date", &Group::setEndDate,
                                  &Group::getEndDate),
          sqlite_orm::foreign_key(&Group::getIdGroup)
            .references(&Performer::getIdPerformer)
            .on_delete.restrict_()
            .on_update.cascade()),
      // Person
      sqlite_orm::make_table(
          "persons",
          sqlite_orm::make_column("id_person", &Person::getIdPerson,
                                  &Person::setIdPerson,
                                  sqlite_orm::primary_key()),
          sqlite_orm::make_column("stage_name", &Person::getStageName,
                                  &Person::setStageName),
          sqlite_orm::make_column("real_name", &Person::getRealName,
                                  &Person::setRealName),
          sqlite_orm::make_column("birth_date", &Person::getBirthDate,
                                  &Person::setBirthDate),
          sqlite_orm::make_column("death_date", &Person::getDeathDate,
                                  &Person::setDeathDate),
          sqlite_orm::foreign_key(&Person::getIdPerson)
            .references(&Performer::getIdPerformer)
            .on_delete.restrict_()
            .on_update.cascade()),
      // In_group
      sqlite_orm::make_table(
          "in_group",
          sqlite_orm::make_column("id_person", &InGroup::getIdPerson,
                                  &InGroup::setIdPerson),
          sqlite_orm::make_column("id_group", &InGroup::getIdGroup,
                                  &InGroup::setIdGroup),
          sqlite_orm::primary_key(&InGroup::getIdPerson, &InGroup::getIdGroup),
          sqlite_orm::foreign_key(&InGroup::getIdPerson)
              .references(&Person::getIdPerson)
              .on_delete.restrict_()
              .on_update.cascade(),
          sqlite_orm::foreign_key(&InGroup::getIdGroup)
              .references(&Group::getIdGroup)
              .on_delete.restrict_()
              .on_update.cascade()),
      // Rola
      sqlite_orm::make_table(
          "rolas",
          sqlite_orm::make_column("id_rola", &Rola::getIdRola, &Rola::setIdRola,
                                  sqlite_orm::primary_key().autoincrement()),
          sqlite_orm::make_column("id_performer", &Rola::getIdPerformer,
                                  &Rola::setIdPerformer),
          sqlite_orm::make_column("id_album", &Rola::getIdAlbum,
                                  &Rola::setIdAlbum),
          sqlite_orm::make_column("path", &Rola::getPath, &Rola::setPath),
          sqlite_orm::make_column("title", &Rola::getTitle, &Rola::setTitle),
          sqlite_orm::make_column("track", &Rola::getTrack, &Rola::setTrack),
          sqlite_orm::make_column("year", &Rola::getYear, &Rola::setYear),
          sqlite_orm::make_column("genre", &Rola::getGenre, &Rola::setGenre),
          sqlite_orm::foreign_key(&Rola::getIdPerformer)
              .references(&Performer::getIdPerformer)
              .on_delete.restrict_()
              .on_update.cascade(),
          sqlite_orm::foreign_key(&Rola::getIdAlbum)
              .references(&Album::getIdAlbum)
              .on_delete.restrict_()
              .on_update.cascade()));
}
using harmony_storage = decltype(make_harmony_storage(""));

class DatabaseConectionManager {
  std::string db_name; // DB name
  std::string db_path; // DB complete path folder_path + db_name
  std::shared_ptr<harmony_storage> storage;
  std::optional<std::string> folder_path;
  bool database_initialized;
  bool create_initial_database;

public:
  ~DatabaseConectionManager();

  static DatabaseConectionManager &getInstance();
  DatabaseConectionManager(const DatabaseConectionManager &) = delete;
  DatabaseConectionManager &
  operator=(const DatabaseConectionManager &) = delete;
  void createAndStartDatabase();
  void setDatabaseFolderPath(const std::string &path);
  const std::string getDatabasePath() const;
  std::shared_ptr<harmony_storage> getHarmonyStorage() const;

private:
  DatabaseConectionManager();
  void createTables();
};

#endif
