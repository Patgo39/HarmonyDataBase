#ifndef DATABASE_CONECTION_MANAGER_H
#define DATABASE_CONECTION_MANAGER_H

#include <iostream>
#include <filesystem>
#include <string>
#include <sqlite3.h>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>


class DatabaseConectionManager{
  
  std::string db_path;
  std::string db_name;
  sqlite3 *db;

public: 
  ~DatabaseConectionManager();
  static DatabaseConectionManager& getInstance();
  DatabaseConectionManager(const DatabaseConectionManager&) = delete;
  DatabaseConectionManager& operator=(const DatabaseConectionManager&) = delete;

private:
  DatabaseConectionManager();
  void createTables();
     
};

#endif
