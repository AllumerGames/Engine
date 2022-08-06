project(WorkSpace)

include_directories(../Engine/Engine
#                     ../Engine/Engine/Events
                    ../Engine/Platform
                    ../Engine/External/spdlog/include
        ../Engine/External/glfw/include
                    )

#add_subdirectory( ../Engine/External/glfw)


add_executable(WorkSpace App.cpp)
target_link_libraries(WorkSpace LINK_PUBLIC Engine)
#target_link_libraries(WorkSpace LINK_PUBLIC Engine)
#target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
