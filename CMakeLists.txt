cmake_minimum_required(VERSION 3.21)
project (Plugin.Core.SamplePlugin)

if (PROJECT_IS_TOP_LEVEL)
    set (CMAKE_CXX_STANDARD 17)
    set (REBELFORK_SDK "" CACHE STRING "Path to pre-built SDK")
    set (CMAKE_PREFIX_PATH ${REBELFORK_SDK}/share)
    find_package(Urho3D REQUIRED)
    include (${REBELFORK_SDK}/share/CMake/Modules/UrhoCommon.cmake)
endif ()

file (GLOB SOURCE_FILES *.h *.cpp)
add_library(${PROJECT_NAME} ${SOURCE_FILES})
setup_plugin_target (${PROJECT_NAME} "${PROJECT_NAME}")
target_link_libraries (${PROJECT_NAME} PUBLIC Urho3D)

if (URHO3D_CSHARP)
    set (DEST_BIN_DIR_CONFIG bin)
    set (DEST_LIBRARY_DIR_CONFIG bin)
    target_include_directories (${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    csharp_bind_target(
        TARGET ${PROJECT_NAME}
        SWIG ${CMAKE_CURRENT_SOURCE_DIR}/CSharp/Plugin.i
        CSPROJ ${CMAKE_CURRENT_SOURCE_DIR}/CSharp/Plugin.csproj
        NAMESPACE Urho3DNet
    )
endif ()

# Generate Visual Studio props file for csproj.
rbfx_configure_cmake_props()
