# Install script for directory: /home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE STATIC_LIBRARY FILES "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-build/taglib/libtag.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/taglib" TYPE FILE FILES
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/tag.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/fileref.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/audioproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/taglib_export.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-build/taglib/../taglib_config.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/taglib.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tstring.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tlist.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tlist.tcc"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tstringlist.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tbytevector.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tbytevectorlist.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tvariant.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tbytevectorstream.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tiostream.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tfilestream.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tmap.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tmap.tcc"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tpicturetype.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tpropertymap.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tdebuglistener.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/toolkit/tversionnumber.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/mpegfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/mpegproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/mpegheader.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/xingheader.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v1/id3v1tag.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v1/id3v1genres.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/id3v2.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/id3v2extendedheader.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/id3v2frame.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/id3v2header.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/id3v2synchdata.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/id3v2footer.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/id3v2framefactory.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/id3v2tag.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/commentsframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/eventtimingcodesframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/ownershipframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/privateframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/synchronizedlyricsframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/unknownframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/urllinkframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/chapterframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/tableofcontentsframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpeg/id3v2/frames/podcastframe.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/oggfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/oggpage.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/oggpageheader.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/xiphcomment.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/vorbis/vorbisfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/vorbis/vorbisproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/flac/oggflacfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/speex/speexfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/speex/speexproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/opus/opusfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ogg/opus/opusproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/flac/flacfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/flac/flacpicture.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/flac/flacproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/flac/flacmetadatablock.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ape/apefile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ape/apeproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ape/apetag.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ape/apefooter.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/ape/apeitem.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpc/mpcfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mpc/mpcproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/wavpack/wavpackfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/wavpack/wavpackproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/trueaudio/trueaudiofile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/trueaudio/trueaudioproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/riff/rifffile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/riff/aiff/aifffile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/riff/aiff/aiffproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/riff/wav/wavfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/riff/wav/wavproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/riff/wav/infotag.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/asf/asffile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/asf/asfproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/asf/asftag.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/asf/asfattribute.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/asf/asfpicture.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mp4/mp4file.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mp4/mp4atom.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mp4/mp4tag.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mp4/mp4item.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mp4/mp4properties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mp4/mp4coverart.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mp4/mp4itemfactory.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mod/modfilebase.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mod/modfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mod/modtag.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/mod/modproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/it/itfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/it/itproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/s3m/s3mfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/s3m/s3mproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/xm/xmfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/xm/xmproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/dsf/dsffile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/dsf/dsfproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/dsdiff/dsdifffile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/dsdiff/dsdiffproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/dsdiff/dsdiffdiintag.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/shorten/shortenfile.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/shorten/shortenproperties.h"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-src/taglib/shorten/shortentag.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/taglib/taglib-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/taglib/taglib-targets.cmake"
         "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-build/taglib/CMakeFiles/Export/af6bba747fd417aafb5802c32959631e/taglib-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/taglib/taglib-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/taglib/taglib-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/taglib" TYPE FILE FILES "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-build/taglib/CMakeFiles/Export/af6bba747fd417aafb5802c32959631e/taglib-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/taglib" TYPE FILE FILES "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-build/taglib/CMakeFiles/Export/af6bba747fd417aafb5802c32959631e/taglib-targets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/taglib" TYPE FILE FILES
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-build/taglib-config.cmake"
    "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-build/taglib-config-version.cmake"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/patriciogarcia/Desktop/Proyects/cpp/projects/HarmonyDB/build/_deps/taglib-build/taglib/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
