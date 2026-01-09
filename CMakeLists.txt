cmake_minimum_required(VERSION 3.20)
project(HarmonyBD VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# -----------------------
# SQLiteCpp
# -----------------------
FetchContent_Declare(
    SQLiteCpp
    GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp
    GIT_TAG 59a047b
)

# -----------------------
# TagLib
# -----------------------
FetchContent_Declare(
    TagLib
    GIT_REPOSITORY https://github.com/taglib/taglib
    GIT_TAG 7d86716
)

FetchContent_MakeAvailable(SQLiteCpp TagLib)

# -----------------------
# Wrapper moderno para TagLib
# -----------------------
add_library(taglib_wrapper INTERFACE)

target_include_directories(taglib_wrapper
    INTERFACE
        ${TagLib_SOURCE_DIR}
        ${TagLib_SOURCE_DIR}/taglib
)

target_link_libraries(taglib_wrapper
    INTERFACE
        tag
)

# -----------------------
# Ejecutable
# -----------------------
add_executable(harmony_bd
    src/main.cpp
)

target_include_directories(harmony_bd
    PRIVATE
        include
)

target_link_libraries(harmony_bd
    PRIVATE
        SQLiteCpp
        taglib_wrapper
)
