#include "../../include/db/database_conection_manager.hpp"

DatabaseConectionManager::DatabaseConectionManager()
    : storage(nullptr), create_initial_database(false) {
  // Configuración de dirección de almacenamiento
  db_name = "database.sqlite3";
  folder_path = std::nullopt;
}

void DatabaseConectionManager::createAndStartDatabase() {
  if (database_initialized) {
    return;
  }
  database_initialized = true;

  std::string home_dir = std::string(getenv("HOME"));
  std::string temp_folder_path =
      (folder_path.has_value() ? *folder_path
                               : home_dir + "/.local/share/harmonydb");
  db_path = temp_folder_path + "/" + db_name;

  // Verificación de existencia de la carpeta
  if (!std::filesystem::exists(temp_folder_path)) {
    if (!std::filesystem::create_directory(temp_folder_path)) {
      throw std::runtime_error("Error creating harmonydb folder in " +
                               temp_folder_path);
    }
  }

  if (!std::filesystem::exists(db_path)) {
    create_initial_database = true;
  }

  createTables();
}

void DatabaseConectionManager::setDatabaseFolderPath(const std::string &path) {
  folder_path = path;
}

DatabaseConectionManager &DatabaseConectionManager::getInstance() {
  static DatabaseConectionManager instancePtr;
  return instancePtr;
}

DatabaseConectionManager::~DatabaseConectionManager() {}

void DatabaseConectionManager::createTables() {
  storage = std::make_shared<harmony_storage>(make_harmony_storage(db_path));
  storage->sync_schema();

  if (create_initial_database) {
    Type t1(1, "Person");
    Type t2(2, "Group");
    Type t3(3, "Unknown");

    storage->insert(t1);
    storage->insert(t2);
    storage->insert(t3);
  }
}

const std::string DatabaseConectionManager::getDatabasePath() const {
  return db_path;
}

std::shared_ptr<harmony_storage>
DatabaseConectionManager::getHarmonyStorage() const {
  return storage;
}