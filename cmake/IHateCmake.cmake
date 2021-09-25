# Did I mention I hate cmake?

include(CheckCCompilerFlag)

# HACKS
set(OLD_DIR ${PROJECT_SOURCE_DIR})
set(PROJECT_SOURCE_DIR "${NVIM_DIR}")
add_subdirectory("${NVIM_DIR}/config")
set(PROJECT_SOURCE_DIR "${OLD_DIR}")
# END HACKS

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

find_package(LuaJit REQUIRED)

find_package(LIBVTERM 0.1 REQUIRED)
include_directories(SYSTEM ${LIBVTERM_INCLUDE_DIRS})

find_package(UNIBILIUM 2.0 REQUIRED)
include_directories(SYSTEM ${UNIBILIUM_INCLUDE_DIRS})

find_package(Iconv REQUIRED)
include_directories(SYSTEM ${Iconv_INCLUDE_DIRS})

find_package(LibTermkey 0.18 REQUIRED)
include_directories(SYSTEM ${LIBTERMKEY_INCLUDE_DIRS})

# NVIM COMMENT
# Use "luv" as imported library, to work around CMake using "-lluv" for
# "luv.so".  #10407
add_library(luv UNKNOWN IMPORTED)
set_property(TARGET luv PROPERTY IMPORTED_LOCATION ${LIBLUV_LIBRARIES})

set(NVIM_LINK_LIBRARIES
  ${LibIntl_LIBRARY}
  ${Iconv_LIBRARIES}
  luv
  m
  util
  ${LIBUV_LIBRARIES}
  ${MSGPACK_LIBRARIES}
  ${LIBVTERM_LIBRARIES}
  ${LIBTERMKEY_LIBRARIES}
  ${UNIBILIUM_LIBRARIES}
  ${UTF8PROC_LIBRARIES}
  ${TreeSitter_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
  ${LUAJIT_LIBRARIES}
  )
