# Nice reference: https://github.com/acmlira/mimicry (specifically the CMakeLists.txt)
cmake_minimum_required(VERSION 3.12...3.21)

project(meovvim
        VERSION 0.1
        LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(NVIM_DIR "${CMAKE_CURRENT_LIST_DIR}/third_party/neovim")
set(SKIA_DIR "${CMAKE_CURRENT_LIST_DIR}/third_party/skia")

include(cmake/IHateCmake.cmake)
include(FindPNG)

add_subdirectory("${PROJECT_SOURCE_DIR}/third_party/glfw/")

# skia
add_library(libskia STATIC IMPORTED)
set_property(TARGET libskia PROPERTY
             IMPORTED_LOCATION
             "${SKIA_DIR}/out/Static/libskia.a")

add_executable(meovvim
  src/main.cpp
  src/ui.c
  src/renderer.cpp
  src/renderer-interface.cpp
)

find_package(ZLIB REQUIRED)

find_library(corefoundation_lib CoreFoundation)
find_library(cfnetwork_lib CFNetwork)

target_link_libraries(meovvim PRIVATE 
  glfw
  ${GLFW_LIBRARIES}
  ${NVIM_LINK_LIBRARIES}
  libnvim
  libskia
  ${ZLIB_LIBRARY}
  ${corefoundation_lib}
  ${cfnetwork_lib}
)

target_include_directories(meovvim
  PUBLIC 
  "${NVIM_DIR}/build/config"
  "${NVIM_DIR}/build/include"
  "${NVIM_DIR}/build/src/nvim/auto"
  "${NVIM_DIR}/src"
  "${NVIM_DIR}/config"
  "${SKIA_DIR}"
  "${PROJECT_SOURCE_DIR}/third_party/glfw/include"
  "${PROJECT_SOURCE_DIR}/src"
)
