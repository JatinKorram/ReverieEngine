if (POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

project(Reverie VERSION 0.0.1)
cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 17)

set(RV_CORE_SOURCES
        "Engine/Source/Core/Application.cpp"
        "Engine/Source/Core/Application.h"
        "Engine/Source/Core/Window.cpp"
        "Engine/Source/Core/Window.h")

set(RV_DRIVER_GLFW_SOURCES
        "Engine/Source/Drivers/GLFW/GLFWWindow.cpp"
        "Engine/Source/Drivers/GLFW/GLFWWindow.h")

set(RV_SERVICE_RENDERING_SOURCES
        "Engine/Source/RenderingService/RenderingContext.cpp"
        "Engine/Source/RenderingService/RenderingContext.h")

set(RV_ENTRY_POINT
        "Engine/Source/Reverie.cpp")

add_executable(Reverie
                    ${RV_CORE_SOURCES}
                    ${RV_DRIVER_GLFW_SOURCES}
                    ${RV_SERVICE_RENDERING_SOURCES}
                    ${RV_ENTRY_POINT})

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")

add_subdirectory("Engine/Source/ThirdParty/glfw")

target_include_directories(Reverie PRIVATE
                                glfw
                                "${CMAKE_SOURCE_DIR}/")

target_link_libraries(Reverie PRIVATE
                                glfw)