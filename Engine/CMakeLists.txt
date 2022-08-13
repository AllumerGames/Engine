#find_package(spdlog REQUIRED)
include_directories(
        External/spdlog/include
#        Engine/Events
#        Engine/ImGui
#        Engine/Renderer
        Engine
        External/imgui
        External/glfw/include
        External/glm
        Platform
        Platform/OpenGL)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")
#set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory(External/glfw)
add_subdirectory(External/glad)
add_subdirectory(External/glm)


add_library(imgui
        External/imgui/imgui.cpp
        External/imgui/imgui.h
        External/imgui/imconfig.h
        External/imgui/imgui_demo.cpp
        External/imgui/imgui_draw.cpp
        External/imgui/imgui_internal.h
        External/imgui/imgui_tables.cpp
        External/imgui/imgui_widgets.cpp
        External/imgui/imstb_rectpack.h
        External/imgui/imstb_textedit.h
        External/imgui/imstb_truetype.h
        )
add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_CUSTOM)
add_definitions(-DGLFW_INCLUDE_NONE)

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

        Engine/Window.hpp

        Engine/Layer.cpp
        Engine/Layer.hpp
        Engine/LayerStack.cpp
        Engine/LayerStack.hpp

        Engine/ImGui/ImGuiLayer.hpp
        Engine/ImGui/ImGuiLayer.cpp

        Platform/Macintosh/MacintoshWindow.cpp
        Platform/Macintosh/MacintoshWindow.hpp

        Engine/ImGui/ImGuiBuild.cpp
        Engine/Input.hpp
        Engine/KeyCodes.hpp
        Engine/MouseButtonCodes.hpp
        Engine/Renderer/GraphicsContexts.hpp
        Platform/OpenGL/OpenGLContext.cpp
        Platform/OpenGL/OpenGLContext.hpp Platform/Macintosh/MacintoshInput.cpp Platform/Macintosh/MacintoshInput.hpp Engine/Renderer/Shader.hpp Engine/Renderer/Shader.cpp)


target_include_directories(Engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE External/glfw/include External/imgui)
#target_link_directories(Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../build/RelWithDebInfo/Engine/External/GLFW/src/)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} glfw glad imgui glm)
