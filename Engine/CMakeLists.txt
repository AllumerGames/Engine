#find_package(spdlog REQUIRED)
include_directories(External/spdlog/include)

add_library(Engine STATIC
        Engine/Log.cpp
        Engine/Log.hpp
        Engine/application.cpp
        Engine/application.hpp
        Engine/Engine.hpp)


target_include_directories(Engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

