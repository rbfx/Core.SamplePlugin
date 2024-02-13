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
define_static_plugin (${PROJECT_NAME} "${PROJECT_NAME}")
target_link_libraries (${PROJECT_NAME} PRIVATE Urho3D)

if (PROJECT_IS_TOP_LEVEL AND URHO3D_CSHARP)
    set (DEST_BIN_DIR_CONFIG bin)
    set (DEST_LIBRARY_DIR_CONFIG bin)
    set (SWIG_DIR "${REBELFORK_SDK}/include/Urho3D/ThirdParty/swig/Lib")
    target_include_directories (${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    include (${REBELFORK_SDK}/share/CMake/Modules/UrhoSWIG.cmake)
    csharp_bind_target(
        TARGET ${PROJECT_NAME}
        SWIG CSharp/Plugin.i
        CSPROJ ${CMAKE_CURRENT_SOURCE_DIR}/CSharp/Plugin.csproj
        NAMESPACE Urho3DNet
        INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR};${REBELFORK_SDK}/include;${REBELFORK_SDK}/include/Urho3D/CSharp/Swig"
    )
    target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}CSharp/PluginCSHARP_wrap.cxx)
endif ()
