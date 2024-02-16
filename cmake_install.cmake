# Install script for directory: C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/modifiedPMSM_Model")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/objects-Debug/modifiedPMSM_Model_objects" TYPE FILE FILES
      "modifiedPMSM_Model.obj"
      "modifiedPMSM_Model_data.obj"
      FILES_FROM_DIR "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/modifiedPMSM_Model_objects.dir/Debug/")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/objects-Release/modifiedPMSM_Model_objects" TYPE FILE FILES
      "modifiedPMSM_Model.obj"
      "modifiedPMSM_Model_data.obj"
      FILES_FROM_DIR "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/modifiedPMSM_Model_objects.dir/Release/")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/objects-MinSizeRel/modifiedPMSM_Model_objects" TYPE FILE FILES
      "modifiedPMSM_Model.obj"
      "modifiedPMSM_Model_data.obj"
      FILES_FROM_DIR "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/modifiedPMSM_Model_objects.dir/MinSizeRel/")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/objects-RelWithDebInfo/modifiedPMSM_Model_objects" TYPE FILE FILES
      "modifiedPMSM_Model.obj"
      "modifiedPMSM_Model_data.obj"
      FILES_FROM_DIR "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/modifiedPMSM_Model_objects.dir/RelWithDebInfo/")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE OPTIONAL FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/Debug/modifiedPMSM_Model.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE OPTIONAL FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/Release/modifiedPMSM_Model.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE OPTIONAL FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/MinSizeRel/modifiedPMSM_Model.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE OPTIONAL FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/RelWithDebInfo/modifiedPMSM_Model.exe")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE OPTIONAL FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/Debug/modifiedPMSM_Model.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE OPTIONAL FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/RelWithDebInfo/modifiedPMSM_Model.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/export/modifiedPMSM_ModelTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/export/modifiedPMSM_ModelTargets.cmake"
         "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/CMakeFiles/Export/3acb0b68e155fdc0feac4f4ad1f8761e/modifiedPMSM_ModelTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/export/modifiedPMSM_ModelTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/export/modifiedPMSM_ModelTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/export" TYPE FILE FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/CMakeFiles/Export/3acb0b68e155fdc0feac4f4ad1f8761e/modifiedPMSM_ModelTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/export" TYPE FILE FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/CMakeFiles/Export/3acb0b68e155fdc0feac4f4ad1f8761e/modifiedPMSM_ModelTargets-debug.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/export" TYPE FILE FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/CMakeFiles/Export/3acb0b68e155fdc0feac4f4ad1f8761e/modifiedPMSM_ModelTargets-minsizerel.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/export" TYPE FILE FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/CMakeFiles/Export/3acb0b68e155fdc0feac4f4ad1f8761e/modifiedPMSM_ModelTargets-relwithdebinfo.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/export" TYPE FILE FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/CMakeFiles/Export/3acb0b68e155fdc0feac4f4ad1f8761e/modifiedPMSM_ModelTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/modifiedPMSM_Model_ert_rtw/export" TYPE FILE FILES "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/modifiedPMSM_Model.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/clara/Documents/University/McSCert/modifiedPMSM_Model_ert_rtw/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
