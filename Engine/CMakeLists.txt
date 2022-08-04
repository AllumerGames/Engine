add_library(Engine STATIC Engine/application.cpp Engine/application.hpp Engine/Engine.hpp)
target_include_directories(Engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
