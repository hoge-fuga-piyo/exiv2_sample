cmake_minimum_required(VERSION 2.8)

set(PROJ_NAME exiv2_sample)
project(${PROJ_NAME})

# Exiv2
find_path(Exiv2_INCLUDE_DIR NAMES exiv2.hpp)
find_library(Exiv2_LIBRARY NAMES exiv2.lib)

include_directories(${Exiv2_INCLUDE_DIR})

file(GLOB PROJ_SOURCE ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB PROJ_HEADER ${CMAKE_SOURCE_DIR}/src/*.h ${CMAKE_SOURCE_DIR}/src/*.hpp)

add_executable(${PROJ_NAME}
  ${PROJ_SOURCE} ${PROJ_HEADER}
)

target_link_libraries(${PROJ_NAME}
  ${Exiv2_LIBRARY}
)
