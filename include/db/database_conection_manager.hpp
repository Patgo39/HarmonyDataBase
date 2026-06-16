#ifndef DATABASE_CONECTION_MANAGER_HPP
#define DATABASE_CONECTION_MANAGER_HPP

#include <iostream>
#include <filesystem>
#include <string>
#include <cstring>
#include <memory>
#include <sqlite3.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../models/person.hpp"

using sqlite3_ptr = std::unique_ptr<sqlite3, decltype(&sqlite3_close)>;

class DatabaseConectionManager{
  std::string db_name;
  sqlite3_ptr db;
  std::string db_path;

public: 
  
  ~DatabaseConectionManager();
  static DatabaseConectionManager& getInstance();
  DatabaseConectionManager(const DatabaseConectionManager&) = delete;
  DatabaseConectionManager& operator=(const DatabaseConectionManager&) = delete;
  const std::string getDatabasePath() const;

private:
  DatabaseConectionManager();
  void createTables();
};

#endif
