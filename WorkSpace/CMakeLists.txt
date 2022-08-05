project(WorkSpace)

include_directories(../Engine/Engine)
include_directories(../Engine/External/spdlog/include)

add_executable(WorkSpace App.cpp)
target_link_libraries(WorkSpace LINK_PUBLIC Engine)
