project(WorkSpace)

include_directories(../Engine/Engine)
add_executable(WorkSpace App.cpp)
target_link_libraries(WorkSpace LINK_PUBLIC Engine)
