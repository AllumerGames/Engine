#find_package(spdlog REQUIRED)
include_directories(External/spdlog/include
                    Engine/Events
        External/glfw/include

        )
find_package( OpenGL REQUIRED )
include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
#set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory(External/glfw)

#add_library(glfw STATIC IMPORTED)
#set_target_properties(glfw PROPERTIES
#        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/lib-vc2019/glfw3.lib"
#        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include")
#target_link_libraries(OpenGL glfw)

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -I/usr/local/lib -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL -lglfw")


add_library(Engine STATIC
        Engine/application.cpp
        Engine/application.hpp
        Engine/Log.cpp
        Engine/Log.hpp
        Engine/Engine.hpp

        Engine/Events/ApplicationEvent.hpp
        Engine/Events/Event.hpp
        Engine/Events/KeyEvent.hpp
        Engine/Events/MouseEvent.hpp

        Engine/Window.h

        Engine/Layer.cpp
        Engine/Layer.hpp
        Engine/LayerStack.cpp
        Engine/LayerStack.hpp

        Platform/Macintosh/MacintoshWindow.cpp
        Platform/Macintosh/MacintoshWindow.hpp


        )


target_include_directories(Engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                                  PRIVATE External/glfw/include)
#target_link_directories(Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../build/RelWithDebInfo/Engine/External/GLFW/src/)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} glfw)
