cmake_minimum_required(VERSION 3.27)

project(
  flecs-atmos
  VERSION 0.0.1
  LANGUAGES CXX
)

set(BUILD_TESTING OFF CACHE BOOL "")

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message( FATAL_ERROR "In-source builds not allowed")
endif()

include(cmake/get_cpm.cmake)

add_executable(flecs-atmos
  src/main.cpp
  src/simd.cpp
  src/simd.hpp
)

set_target_properties(flecs-atmos PROPERTIES
  CXX_EXTENSIONS ON
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
)
target_compile_options(flecs-atmos PRIVATE
  $<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->
  #$<IF:$<CXX_COMPILER_ID:MSVC>,/W4,-Wall -Wextra -Wpedantic>
  -Wno-microsoft-include
)

set(HWY_ENABLE_CONTRIB OFF CACHE BOOL "")
set(HWY_ENABLE_EXAMPLES OFF CACHE BOOL "")
set(HWY_ENABLE_INSTALL OFF CACHE BOOL "")
set(HWY_ENABLE_TESTS OFF CACHE BOOL "")
set(HWY_FORCE_STATIC_LIBS ON CACHE BOOL "")

CPMAddPackage(
  NAME hwy
  URL https://github.com/google/highway/archive/refs/tags/1.0.7.tar.gz
  URL_HASH SHA3_256=034dbaa5c2253ec1c50e61c8c867736c6019420b71e2d2c6cb0a435ab2286778
)
target_link_libraries(flecs-atmos PRIVATE hwy)