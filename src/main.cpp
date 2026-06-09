#include <iostream>
#include "../include/db/database_conection_manager.hpp"

int main(){

    std::cout<<"Hello world!"<<std::endl;
    DatabaseConectionManager &dc = DatabaseConectionManager::getInstance();

    return 0;
}
