cmake_minimum_required(VERSION 3.16...3.22)

project(
        Engine
        VERSION 0.0.1
        DESCRIPTION "cpp game engine"
        HOMEPAGE_URL ""
        LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF) # to avoid conflicts between -Wpedantic being enabled and -std=c++20 and -std=gnu++20

# This means that all analysis (sanitizers, static analysis)
# is enabled and all warnings are treated as errors
set(ENABLE_DEVELOPER_MODE TRUE CACHE BOOL "Enable 'developer mode'")

set(OPT_WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT TRUE)

set(TARGET_ROOT_DIR ${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})
set(TARGET_BIN_DIR ${TARGET_ROOT_DIR}/bin)
set(TARGET_LIB_DIR ${TARGET_ROOT_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TARGET_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TARGET_LIB_DIR})

add_subdirectory(Engine)
add_subdirectory(WorkSpace)

target_precompile_headers(
        Engine PRIVATE
        <iostream>
        <memory>
        <vector>
        <string>
        <sstream>
        <array>
        <set>
        <unordered_map>
        <map>
        <functional>
        "Engine/Engine/Log.hpp")
