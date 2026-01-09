# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/sqlitecpp-src")
  file(MAKE_DIRECTORY "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/sqlitecpp-src")
endif()
file(MAKE_DIRECTORY
  "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/sqlitecpp-build"
  "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/sqlitecpp-subbuild/sqlitecpp-populate-prefix"
  "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/sqlitecpp-subbuild/sqlitecpp-populate-prefix/tmp"
  "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/sqlitecpp-subbuild/sqlitecpp-populate-prefix/src/sqlitecpp-populate-stamp"
  "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/sqlitecpp-subbuild/sqlitecpp-populate-prefix/src"
  "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/sqlitecpp-subbuild/sqlitecpp-populate-prefix/src/sqlitecpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/sqlitecpp-subbuild/sqlitecpp-populate-prefix/src/sqlitecpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/sqlitecpp-subbuild/sqlitecpp-populate-prefix/src/sqlitecpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
