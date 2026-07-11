cmake_minimum_required(VERSION 3.20)

project(
    IdleMMORPGEngine
    VERSION 0.1.0
    DESCRIPTION "Cross-platform MMORPG idle RPG"
    LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if(MSVC)

    add_compile_options(/W4)

else()

    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
    )

endif()


include(FetchContent)


FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)


FetchContent_MakeAvailable(json)


file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)


add_executable(
    IdleMMORPGEngine
    ${SOURCES}
)


target_include_directories(
    IdleMMORPGEngine
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)


target_link_libraries(
    IdleMMORPGEngine
    PRIVATE
    nlohmann_json::nlohmann_json
)