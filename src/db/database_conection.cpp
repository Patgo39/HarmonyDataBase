#include "../../include/db/database_conection.h"

DatabaseConection::DatabaseConection(){
  db_name = "database.db";
  std::string home_dir = std::string(getenv("HOME"));
  std::string folder_path = home_dir + "/.local/share/harmonydb";
  db_path = folder_path + db_name;

  if(!std::filesystem::exists(folder_path)){
    if(!std::filesystem::create_directory(folder_path)){
      std::cout<<"Error creando el directorio en .local\n";
    }
    
  }
  
}


