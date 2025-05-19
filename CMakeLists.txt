cmake_minimum_required(VERSION 3.10)
project(SDL_osu)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        main.cpp
        Game.cpp
        Circle.cpp
        Beatmap.cpp
        HitObject.cpp
        ApproachCircle.cpp
)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(/usr/include/SDL2)
link_directories(/usr/lib/x86_64-linux-gnu)
add_executable(SDL_osu ${SOURCES})
target_link_libraries(SDL_osu ${SDL2_LIBRARIES} SDL2_image SDL2)
