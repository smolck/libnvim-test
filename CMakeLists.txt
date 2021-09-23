# Nice reference: https://github.com/acmlira/mimicry (specifically the CMakeLists.txt)
cmake_minimum_required(VERSION 3.12...3.21)

project(meovvim
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/third_party/skia/cmake" EXCLUDE_FROM_ALL)
# add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/skia" )
set(SKIA_LIBRARY skia)

add_executable(meovvim src/main.cpp)

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(meovvim PRIVATE ${SKIA_LIBRARY})

target_include_directories(meovvim
  PUBLIC 
  "${CMAKE_CURRENT_LIST_DIR}/third_party/skia/")
