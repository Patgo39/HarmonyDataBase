#include <iostream>
#include "../include/db/database_conection_manager.hpp"
#include "../include/daos/person_dao.hpp"
#include "../include/daos/album_dao.hpp"
#include <sstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

int main(){

    std::cout<<"Hello world!"<<std::endl;

    std::time_t now = std::time(nullptr);
    
    // Convert to local time structure safely
    std::tm localTime = *std::localtime(&now);
    
    // Stream into a string
    std::stringstream ss;
    ss << std::put_time(&localTime, "%Y-%m-%d"); // Format: YYYY-MM-DD
    
    std::string s = ss.str();

    std::cout<<s<<std::endl;

    return 0;
}
