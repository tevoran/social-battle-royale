cmake_minimum_required(VERSION 3.16)
project("sbr")

#BASICALLY RELEASE MODE
SET(CMAKE_CXX_FLAGS  "-m64 -Ofast -flto -march=native -funroll-loops")

#DEBUGMODE
#SET(CMAKE_CXX_FLAGS "-g -ggdb -fsanitize=address")
#SET(CMAKE_CXX_FLAGS "-g")

#PROFILERMODE
#SET(CMAKE_CXX_FLAGS "-g -pg")

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(FindPkgConfig)
find_library(SDL2 SDL2)
find_package(SDL2 REQUIRED)
find_library(SDL2_ttf SDL2_ttf)
find_library(GLEW GLEW)
find_library(GL GL)


#creating the executable
include_directories(src/)
include_directories(vendor/TGJGE/src/)
include_directories(vendor/TGJGE/vendor/stb/)
file(GLOB_RECURSE "engine" SRC vendor/TGJGE/src/*.c)
file(GLOB_RECURSE "game" SRC src/*.cpp)
add_executable(sbr ${engine} ${game})

target_link_libraries(sbr LINK_PRIVATE "${SDL2}")
target_link_libraries(sbr LINK_PRIVATE "${SDL2_ttf}")
target_link_libraries(sbr LINK_PRIVATE m)
target_link_libraries(sbr LINK_PRIVATE "${GLEW}")
target_link_libraries(sbr LINK_PRIVATE "${GL}")

#copy engine shaders
file(COPY vendor/TGJGE/shaders DESTINATION .)
