cmake_minimum_required(VERSION 3.23)
project(FoxiiiSimmulator)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE CPPFILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HPPFILES ${CMAKE_SOURCE_DIR}/src/*.hpp)

add_executable(FoxiiiSimmulator ${CPPFILES} ${HPPFILES})

target_link_libraries(FoxiiiSimmulator ${CMAKE_SOURCE_DIR}/lib/SDL2.lib ${CMAKE_SOURCE_DIR}/lib/SDL2main.lib
        ${CMAKE_SOURCE_DIR}/lib/SDL2_ttf.lib)
