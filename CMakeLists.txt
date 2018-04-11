cmake_minimum_required(VERSION 3.0)

project(SFML_Essentials)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")
find_package (SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
endif()

add_executable(01_01 Chapter_1/01.cpp)
target_link_libraries(01_01 ${SFML_LIBRARIES})
target_compile_features(01_01 PUBLIC cxx_std_11)

add_executable(01_02 Chapter_1/02.cpp)
target_link_libraries(01_02 ${SFML_LIBRARIES})
target_compile_features(01_02 PUBLIC cxx_std_11)

add_executable(01_03 Chapter_1/03.cpp)
target_link_libraries(01_03 ${SFML_LIBRARIES})
target_compile_features(01_03 PUBLIC cxx_std_11)

add_executable(01_04 Chapter_1/04.cpp)
target_link_libraries(01_04 ${SFML_LIBRARIES})
target_compile_features(01_04 PUBLIC cxx_std_11)

add_executable(01_05 Chapter_1/05.cpp)
target_link_libraries(01_05 ${SFML_LIBRARIES})
target_compile_features(01_05 PUBLIC cxx_std_11)

add_executable(01_06 Chapter_1/06.cpp)
target_link_libraries(01_06 ${SFML_LIBRARIES})
target_compile_features(01_06 PUBLIC cxx_std_11)

add_executable(01_07 Chapter_1/07.cpp)
target_link_libraries(01_07 ${SFML_LIBRARIES})
target_compile_features(01_07 PUBLIC cxx_std_11)

add_executable(01_08 Chapter_1/08.cpp)
target_link_libraries(01_08 ${SFML_LIBRARIES})
target_compile_features(01_08 PUBLIC cxx_std_11)

add_executable(01_11 Chapter_1/11.cpp)
target_link_libraries(01_11 ${SFML_LIBRARIES})
target_compile_features(01_11 PUBLIC cxx_std_11)

add_executable(01_13 Chapter_1/13.cpp)
target_link_libraries(01_13 ${SFML_LIBRARIES})
target_compile_features(01_13 PUBLIC cxx_std_11)

add_executable(01_15 Chapter_1/15.cpp)
target_link_libraries(01_15 ${SFML_LIBRARIES})
target_compile_features(01_15 PUBLIC cxx_std_11)

add_executable(01_18 Chapter_1/18.cpp)
target_link_libraries(01_18 ${SFML_LIBRARIES})
target_compile_features(01_18 PUBLIC cxx_std_11)

add_executable(02_09 Chapter_2/09.cpp)
target_link_libraries(02_09 ${SFML_LIBRARIES})
target_compile_features(02_09 PUBLIC cxx_std_11)

add_executable(02_11 Chapter_2/11.cpp)
target_link_libraries(02_11 ${SFML_LIBRARIES})
target_compile_features(02_11 PUBLIC cxx_std_11)

add_executable(02_13 Chapter_2/13.cpp)
target_link_libraries(02_13 ${SFML_LIBRARIES})
target_compile_features(02_13 PUBLIC cxx_std_11)

add_executable(02_16 Chapter_2/16.cpp)
target_link_libraries(02_16 ${SFML_LIBRARIES})
target_compile_features(02_16 PUBLIC cxx_std_11)

add_executable(02_18 Chapter_2/18.cpp)
target_link_libraries(02_18 ${SFML_LIBRARIES})
target_compile_features(02_18 PUBLIC cxx_std_11)

add_executable(03_08 Chapter_3/08.cpp Chapter_3/AssetManagement/AssetManager.cpp)
target_link_libraries(03_08 ${SFML_LIBRARIES})
target_compile_features(03_08 PUBLIC cxx_std_11)

add_executable(03_06 Chapter_3/06.cpp)
target_link_libraries(03_06 ${SFML_LIBRARIES})
target_compile_features(03_06 PUBLIC cxx_std_11)

add_executable(04_06 Chapter_4/06.cpp Chapter_4/AssetManagement/AssetManager.cpp)
target_link_libraries(04_06 ${SFML_LIBRARIES})
target_compile_features(04_06 PUBLIC cxx_std_11)

add_executable(04_13 Chapter_4/13.cpp Chapter_4/AssetManagement/AssetManager.cpp)
target_link_libraries(04_13 ${SFML_LIBRARIES})
target_compile_features(04_13 PUBLIC cxx_std_11)

add_executable(04_16 Chapter_4/16.cpp)
target_link_libraries(04_16 ${SFML_LIBRARIES})
target_compile_features(04_16 PUBLIC cxx_std_11)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
  "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")

add_custom_target(compile_commands ALL)

add_custom_command(
  TARGET compile_commands POST_BUILD
  COMMAND touch ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
  COMMAND cp ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR})

add_custom_command(
  TARGET  02_13 PRE_BUILD
  COMMAND cp ${CMAKE_SOURCE_DIR}/Assets/leaf.png ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(
  TARGET  02_11 PRE_BUILD
  COMMAND cp ${CMAKE_SOURCE_DIR}/Assets/leaf.png ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(
  TARGET  02_09 PRE_BUILD
  COMMAND cp ${CMAKE_SOURCE_DIR}/Assets/leaf.png ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(
  TARGET  02_16 PRE_BUILD
  COMMAND cp ${CMAKE_SOURCE_DIR}/Assets/cube.png ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(
  TARGET  02_18 PRE_BUILD
  COMMAND cp ${CMAKE_SOURCE_DIR}/Assets/leaf.png ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(
  TARGET  03_08 PRE_BUILD
  COMMAND cp ${CMAKE_SOURCE_DIR}/Assets/crystal.png ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(
  TARGET  04_06 PRE_BUILD
  COMMAND cp ${CMAKE_SOURCE_DIR}/Assets/leaf.png ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(
  TARGET  04_13 PRE_BUILD
  COMMAND cp ${CMAKE_SOURCE_DIR}/Assets/leaf.png ${CMAKE_CURRENT_BINARY_DIR})

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
  "${CMAKE_CURRENT_BINARY_DIR}/leaf.png"
  "${CMAKE_CURRENT_BINARY_DIR}/egg.png"
  "${CMAKE_CURRENT_BINARY_DIR}/crystal.png"
  "${CMAKE_CURRENT_BINARY_DIR}/cube.png")
