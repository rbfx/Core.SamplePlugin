cmake_minimum_required(VERSION 3.21)
project (Plugin.Core.SamplePlugin)

# Top-level plugin build is not supported yet.
# If the plugin is only built as subdirectory, this snippet is not needed and may be discarded.
if (PROJECT_IS_TOP_LEVEL)
    set (CMAKE_CXX_STANDARD 17)
    set (REBELFORK_SDK "" CACHE STRING "Path to pre-built SDK")
    set (CMAKE_PREFIX_PATH ${REBELFORK_SDK}/share)
    find_package (Urho3D REQUIRED)
    include (${REBELFORK_SDK}/share/CMake/Modules/UrhoCommon.cmake)
endif ()

file (GLOB_RECURSE SOURCE_FILES *.h *.cpp)
add_plugin (${PROJECT_NAME} "${SOURCE_FILES}")
