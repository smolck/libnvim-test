# Nice reference: https://github.com/acmlira/mimicry (specifically the CMakeLists.txt)
cmake_minimum_required(VERSION 3.12...3.21)

project(meovvim
        VERSION 0.1
        LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(NVIM_DIR "${CMAKE_CURRENT_LIST_DIR}/third_party/neovim")
set(SKIA_DIR "${CMAKE_CURRENT_LIST_DIR}/third_party/skia")

# HACKS
# TODO(smolck): Is there a way to do this without . . . this?
set(OLD_DIR ${PROJECT_SOURCE_DIR})
set(PROJECT_SOURCE_DIR "${NVIM_DIR}")
add_subdirectory("${NVIM_DIR}/config")
set(PROJECT_SOURCE_DIR "${OLD_DIR}")

# libnvim (TODO(smolck): Check all this is necessary with the find packages and
# stuff)
add_library(libnvim STATIC IMPORTED)
set_property(TARGET libnvim PROPERTY
             IMPORTED_LOCATION
             "${NVIM_DIR}/build/lib/libnvim.a")

# Make nvim's cmake modules available for use
list(INSERT CMAKE_MODULE_PATH 0 "${NVIM_DIR}/cmake")

find_package(LibIntl REQUIRED)
include_directories(SYSTEM ${LibIntl_INCLUDE_DIRS})
find_package(LibUV 1.28.0 REQUIRED)
include_directories(SYSTEM ${LIBUV_INCLUDE_DIRS})
find_package(Msgpack 1.0.0 REQUIRED)
include_directories(SYSTEM ${MSGPACK_INCLUDE_DIRS})
find_package(LibLUV 1.30.0 REQUIRED)
include_directories(SYSTEM ${LIBLUV_INCLUDE_DIRS})
find_package(TreeSitter REQUIRED)
include_directories(SYSTEM ${TreeSitter_INCLUDE_DIRS})

# skia
add_library(libskia STATIC IMPORTED)
set_property(TARGET libskia PROPERTY
             IMPORTED_LOCATION
             "${SKIA_DIR}/out/Static/libskia.a")

add_executable(meovvim src/main.cpp src/libnvim.c)

target_link_libraries(meovvim PRIVATE libnvim libskia)

target_include_directories(meovvim
  PUBLIC 
  "${NVIM_DIR}/build/config"
  "${NVIM_DIR}/build/include"
  "${NVIM_DIR}/src/"
  "${PROJECT_SOURCE_DIR}/third_party/skia/"
  "${PROJECT_SOURCE_DIR}/third_party/neovim/config/")
