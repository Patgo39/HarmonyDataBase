#ifndef DATABASE_CONECTION_MANAGER_HPP
#define DATABASE_CONECTION_MANAGER_HPP

#include <iostream>
#include <filesystem>
#include <string>
#include <sqlite3.h>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>
#include "../models/person.hpp"


class DatabaseConectionManager{
  std::string db_name;
  sqlite3 *db;
  std::string db_path;

public: 
  
  ~DatabaseConectionManager();
  static DatabaseConectionManager& getInstance();
  DatabaseConectionManager(const DatabaseConectionManager&) = delete;
  DatabaseConectionManager& operator=(const DatabaseConectionManager&) = delete;
  const sqlite3* getDatabaseConectionPointer() const;
  const std::string getDatabasePath() const;

private:
  DatabaseConectionManager();
  void createTables();
};

#endif
