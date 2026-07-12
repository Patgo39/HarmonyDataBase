
cmake_minimum_required(VERSION 3.20)
project(HarmonyBD VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

find_package(ZLIB REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(PkgConfig REQUIRED)
pkg_check_modules(TAGLIB REQUIRED taglib)

FetchContent_Declare(
  sqlite_orm
  GIT_REPOSITORY https://github.com/fnc12/sqlite_orm.git
  GIT_TAG        v1.9.1
)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SQLITE_ORM_BUILD_TESTS OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(sqlite_orm)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/dependencies/SQLiteCpp)

set(SRC_FILES
  #DB
  src/db/database_conection_manager.cpp
  # models
  src/models/album.cpp 
  src/models/group.cpp 
  src/models/in_group.cpp 
  src/models/performer.cpp 
  src/models/person.cpp
  src/models/rola.cpp

  #daos
  src/daos/album_dao.cpp 
  src/daos/group_dao.cpp 
  src/daos/in_group_dao.cpp 
  src/daos/performer_dao.cpp 
  src/daos/person_dao.cpp
  src/daos/rola_dao.cpp

  #utils
  src/utils/string_utils.cpp
  src/utils/time_utils.cpp
  src/utils/type_enum.cpp
)

add_executable(harmony_bd
  src/main.cpp
  ${SRC_FILES}

)


set_target_properties(harmony_bd PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

target_include_directories(harmony_bd
    PRIVATE
    include
    ${TAGLIB_INCLUDE_DIRS}
)

target_link_libraries(harmony_bd
    PRIVATE
      Qt6::Widgets
	    sqlite_orm::sqlite_orm
      SQLiteCpp
      ${TAGLIB_LIBRARIES}
)

enable_testing()

add_executable(dao_test
    #Tests daos
    #tests/test_daos/test_album_dao.cpp
    tests/test_daos/test_group_dao.cpp
    #tests/test_daos/test_in_group_dao.cpp
    #tests/test_daos/test_performer_dao.cpp
    tests/test_daos/test_person_dao.cpp
    #tests/test_daos/test_rola_dao.cpp

    # Test models
    tests/test_models/test_album.cpp
    tests/test_models/test_group.cpp
    tests/test_models/test_performer.cpp
    tests/test_models/test_person.cpp
    tests/test_models/test_rola.cpp
    ${SRC_FILES}
)

target_link_libraries(dao_test 
    GTest::gtest_main
    sqlite_orm::sqlite_orm
)

include(GoogleTest)
gtest_discover_tests(dao_test)
