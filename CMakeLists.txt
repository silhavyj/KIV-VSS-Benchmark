cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
    benchmark
    VERSION 0.0.1
    DESCRIPTION "KIV/VSS - Task 04 (benchmark)"
    LANGUAGES CXX C
)

include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.2
)

FetchContent_MakeAvailable(json)

add_subdirectory(src)
