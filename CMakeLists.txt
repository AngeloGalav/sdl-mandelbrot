cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED ON)

project(sdl_mandelbrot)

file(GLOB_RECURSE SRC_FILES src/*.c*)

find_package(SDL2 REQUIRED)

add_executable(sdl_mandelbrot ${SRC_FILES})
target_include_directories(sdl_mandelbrot
 PUBLIC
 ${CMAKE_CURRENT_SOURCE_DIR}/src/include
 ${SDL2_INCLUDE_DIRS})

target_link_libraries(sdl_mandelbrot
 PUBLIC
 ${SDL2_LIBRARIES}
 pthread)
