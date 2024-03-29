cmake_minimum_required(VERSION 3.27)
project(PlatformGame)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.1.1
)

FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
)

FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(sfml)

add_executable(PlatformGame GameFiles/main.cpp
        GameFiles/Game.h
        GameFiles/Game.cpp
        GameFiles/Player.cpp
        GameFiles/Player.h
        GameFiles/Tile.cpp
        GameFiles/Tile.h
        GameFiles/TileMap.cpp
        GameFiles/TileMap.h


)
target_link_libraries(
        PlatformGame
        fmt
        sfml-graphics
        sfml-window
        sfml-system
)

IF (WIN32)
    add_custom_command(TARGET PlatformGame POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:PlatformGame> $<TARGET_FILE_DIR:PlatformGame>
            COMMAND_EXPAND_LISTS
    )
ENDIF ()

