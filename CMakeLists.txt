######################################################################
# CMakeLists.txt generated for component modifiedPMSM_Model
# Product type: executable
######################################################################
cmake_minimum_required(VERSION 3.12)
project(modifiedPMSM_Model)
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


######################################################################
## Path variables
######################################################################
get_filename_component(START_DIR .. ABSOLUTE)
set(MATLAB_ROOT C:/Program\ Files/MATLAB/R2023a CACHE PATH "")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
if(${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    set(BUILDING_IN_SOURCE_DIR TRUE)
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BUILDING_IN_SOURCE_DIR FALSE)
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()
if(WIN32 AND NOT MINGW)
    set(SYSLIB_PREFIX "lib")
else()
    set(SYSLIB_PREFIX "")
endif()

######################################################################
## System libraries
######################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES}
    ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

######################################################################
## Target definition and commands
######################################################################
set(MODIFIEDPMSM_MODEL_COMMON_DEFINES -DMODEL=modifiedPMSM_Model
    -DNUMST=2
    -DNCSTATES=4
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=1
    -DTERMFCN=1
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=0
    -DINTEGER_CODE=0
    -DMT=0
    -D_CRT_SECURE_NO_WARNINGS)

set(MODIFIEDPMSM_MODEL_COMMON_COMPILER_FLAGS /wd4251
    -EHs)

add_library(modifiedPMSM_Model_objects OBJECT ${START_DIR}/modifiedPMSM_Model_ert_rtw/modifiedPMSM_Model.c
    ${START_DIR}/modifiedPMSM_Model_ert_rtw/modifiedPMSM_Model_data.c)
set_target_properties(modifiedPMSM_Model_objects PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)
target_compile_features(modifiedPMSM_Model_objects PUBLIC c_std_99)
target_compile_definitions(modifiedPMSM_Model_objects PRIVATE ${MODIFIEDPMSM_MODEL_COMMON_DEFINES})
target_compile_options(modifiedPMSM_Model_objects PRIVATE ${MODIFIEDPMSM_MODEL_COMMON_COMPILER_FLAGS})
target_include_directories(modifiedPMSM_Model_objects PUBLIC $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>>
    $<BUILD_INTERFACE:${START_DIR}/modifiedPMSM_Model_ert_rtw>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/modifiedPMSM_Model_ert_rtw>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/simulink/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src/ext_mode/common>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/ert>)
target_link_libraries(modifiedPMSM_Model_objects PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>)

add_executable(modifiedPMSM_Model  ${START_DIR}/modifiedPMSM_Model_ert_rtw/ert_main.c)
set_target_properties(modifiedPMSM_Model PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)
target_compile_features(modifiedPMSM_Model PUBLIC c_std_99)
target_compile_definitions(modifiedPMSM_Model PRIVATE ${MODIFIEDPMSM_MODEL_COMMON_DEFINES})
target_compile_options(modifiedPMSM_Model PRIVATE ${MODIFIEDPMSM_MODEL_COMMON_COMPILER_FLAGS})
target_link_libraries(modifiedPMSM_Model PRIVATE modifiedPMSM_Model_objects)
if(WIN32)
   target_link_libraries(modifiedPMSM_Model PRIVATE kernel32
       ws2_32
       mswsock
       advapi32)
endif()


add_executable(MotorSimulation  
    ert_main.c 
)
set_target_properties(MotorSimulation PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)
target_compile_features(MotorSimulation PUBLIC c_std_99)
target_compile_definitions(MotorSimulation PRIVATE ${MODIFIEDPMSM_MODEL_COMMON_DEFINES})
target_compile_options(MotorSimulation PRIVATE ${MODIFIEDPMSM_MODEL_COMMON_COMPILER_FLAGS})
target_link_libraries(MotorSimulation PRIVATE modifiedPMSM_Model_objects)
if(WIN32)
   target_link_libraries(MotorSimulation PRIVATE kernel32
       ws2_32
       mswsock
       advapi32)
endif()

######################################################################
## Extract debug symbols
######################################################################
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:modifiedPMSM_Model>;--flat,"
                "true"
        >)
    add_custom_command(TARGET modifiedPMSM_Model
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS modifiedPMSM_Model.dwarf)
endif()


######################################################################
## Target install and export rules
######################################################################
install(TARGETS modifiedPMSM_Model_objects EXPORT modifiedPMSM_ModelTargets OBJECTS DESTINATION modifiedPMSM_Model_ert_rtw)
install(TARGETS modifiedPMSM_Model RUNTIME DESTINATION . OPTIONAL)
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    install(FILES $<TARGET_FILE_DIR:modifiedPMSM_Model>/modifiedPMSM_Model.dwarf DESTINATION . OPTIONAL CONFIGURATIONS Debug RelWithDebInfo)
endif()
if(CMAKE_C_LINKER_SUPPORTS_PDB)
    install(FILES $<TARGET_PDB_FILE:modifiedPMSM_Model> DESTINATION . OPTIONAL CONFIGURATIONS Debug RelWithDebInfo)
endif()
install(EXPORT modifiedPMSM_ModelTargets NAMESPACE modifiedPMSM_Model:: DESTINATION modifiedPMSM_Model_ert_rtw/export)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/modifiedPMSM_Model.cmake 
 "include(\"\${CMAKE_CURRENT_LIST_DIR}/modifiedPMSM_ModelTargets.cmake\")" \n
    "target_include_directories(modifiedPMSM_Model::modifiedPMSM_Model_objects INTERFACE \n"
    "    \${MATLAB_ROOT}/extern/include" \n 
    "    \${MATLAB_ROOT}/simulink/include" \n 
    "    \${MATLAB_ROOT}/rtw/c/src" \n 
    "    \${MATLAB_ROOT}/rtw/c/src/ext_mode/common" \n 
    "    \${MATLAB_ROOT}/rtw/c/ert)" \n )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/modifiedPMSM_Model.cmake DESTINATION modifiedPMSM_Model_ert_rtw/export)

######################################################################
## Build success message
######################################################################
add_custom_command(TARGET modifiedPMSM_Model POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:modifiedPMSM_Model>")

######################################################################
## Call toolchain hook function if defined
######################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(modifiedPMSM_Model)
endif()












