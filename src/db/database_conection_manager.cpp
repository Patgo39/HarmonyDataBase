#include "../../include/db/database_conection_manager.hpp"

DatabaseConectionManager::DatabaseConectionManager(){
  // Configuración de dirección de almacenamiento
  db_name = "database.sqlite3";
  bool create_tables;
  std::string home_dir = std::string(getenv("HOME"));
  std::string folder_path = home_dir + "/.local/share/harmonydb";
  db_path = folder_path +"/"+ db_name;

  // Verificación de existencia de la base de datos
  if(!std::filesystem::exists(folder_path)){
    if(!std::filesystem::create_directory(folder_path)){
      throw std::runtime_error("Error creating harmonydb folder in .local/share");
    }
  }

  if(!std::filesystem::exists(db_path)){
    create_tables = true;
  }
  
  // Abrir la base de datos
  if(sqlite3_open(db_path.c_str(), &db)){
    throw std::runtime_error("Error opening the database.");
    
  }else{
    if(create_tables){
      createTables();
    }
  }
  
}

DatabaseConectionManager& DatabaseConectionManager::getInstance(){
  static DatabaseConectionManager instancePtr;
  return instancePtr;
}

DatabaseConectionManager::~DatabaseConectionManager(){
  sqlite3_close(db);
}

void DatabaseConectionManager::createTables(){
  const char* sql = R"sql(
CREATE TABLE IF NOT EXISTS types (
    id_type       INTEGER PRIMARY KEY,
    description   TEXT
);

INSERT INTO types VALUES(0,'Person');
INSERT INTO types VALUES(1,'Group');
INSERT INTO types VALUES(2,'Unknown');

CREATE TABLE IF NOT EXISTS performers (
    id_performer  INTEGER PRIMARY KEY,
    id_type       INTEGER,
    name          TEXT,
    FOREIGN KEY   (id_type) REFERENCES types(id_type)
);

CREATE TABLE IF NOT EXISTS persons (
    id_person     INTEGER PRIMARY KEY,
    stage_name    TEXT,
    real_name     TEXT,
    birth_date    TEXT,
    death_date    TEXT
);

CREATE TABLE IF NOT EXISTS groups (
    id_group      INTEGER PRIMARY KEY,
    name          TEXT,
    start_date    TEXT,
    end_date      TEXT
);

CREATE TABLE IF NOT EXISTS in_group (
    id_person     INTEGER,
    id_group      INTEGER,
    PRIMARY KEY   (id_person, id_group),
    FOREIGN KEY   (id_person) REFERENCES persons(id_person),
    FOREIGN KEY   (id_group) REFERENCES groups(id_group)
);

CREATE TABLE IF NOT EXISTS albums (
    id_album      INTEGER PRIMARY KEY,
    path          TEXT,
    name          TEXT,
    year          INTEGER
);

CREATE TABLE IF NOT EXISTS rolas (
    id_rola       INTEGER PRIMARY KEY,
    id_performer  INTEGER,
    id_album      INTEGER,
    path          TEXT,
    title         TEXT,
    track         INTEGER,
    year          INTEGER,
    genre         TEXT,
    FOREIGN KEY   (id_performer) REFERENCES performers(id_performer),
    FOREIGN KEY   (id_album) REFERENCES albums(id_album)
);
)sql";

  char* errMsg = nullptr;
  int response = sqlite3_exec(db, sql, NULL, 0, &errMsg);

  if(response != SQLITE_OK){
    std::string error_str = "Error in creation of tables: ";

    if(errMsg != nullptr){
      error_str += errMsg;
    }

    sqlite3_free(errMsg);

    throw std::runtime_error(error_str);
  }
}


