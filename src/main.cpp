#include <iostream>
#include "../include/db/database_conection_manager.hpp"
#include "../include/daos/person_dao.hpp"
#include "../include/daos/album_dao.hpp"
#include <sstream>

int main(){

    std::cout<<"Hello world!"<<std::endl;
    DatabaseConectionManager &dc = DatabaseConectionManager::getInstance();

    return 0;
}
