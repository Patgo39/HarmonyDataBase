
cmake_minimum_required(VERSION 3.20)
project(HarmonyBD VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

find_package(ZLIB REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(SQLite3 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(TAGLIB REQUIRED taglib)

FetchContent_Declare(
  sqlite_orm
  GIT_REPOSITORY https://github.com/fnc12/sqlite_orm.git
  GIT_TAG        v1.9.1
)

set(SQLITE_ORM_BUILD_TESTS OFF CACHE INTERNAL "")

FetchContent_MakeAvailable(sqlite_orm)

add_executable(harmony_bd
  src/main.cpp
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
        SQLite::SQLite3
        Qt6::Widgets
	sqlite_orm::sqlite_orm
        ${TAGLIB_LIBRARIES}
)
