#ifndef DATABASE_CONECTION_H
#define DATABASE_CONECTION_H

#include <iostream>
#include <filesystem>
#include <string>
#include <sqlite3.h>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>


class DatabaseConection{
  
  std::string db_path;
  std::string db_name;
  sqlite3 *db;

 public: 
  DatabaseConection();

     
};

#endif
