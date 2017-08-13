#ART version
set(ART_VERSION_MAJOR 0)
set(ART_VERSION_MINOR 0)
set(ART_VERSION_PATCH 1)
set(ART_VERSION ${ART_VERSION_MAJOR}.${ART_VERSION_MINOR}.${ART_VERSION_PATCH})

################################################################################
project(AndroidReverseToolkitQ LANGUAGES CXX)
cmake_minimum_required(VERSION 2.8.12)

set(ECM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/KDE/share/ECM/cmake)
find_package(ECM 5.37.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} )
if(POLICY CMP0063)
    cmake_policy(SET CMP0063 NEW)
endif()

include(KDEInstallDirs)
include(KDECompilerSettings)
include(KDECMakeSettings)
include(ECMSetupVersion)

ecm_setup_version(${ART_VERSION_MAJOR}.${ART_VERSION_MINOR}.${ART_VERSION_PATCH}
        VARIABLE_PREFIX ART
        VERSION_HEADER "${CMAKE_CURRENT_BINARY_DIR}/art_version.h"
        PACKAGE_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/ARTConfigVersion.cmake")



set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Qt
# ******************************************************************************
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# definitions

if(WIN32 OR WIN64)
    message("Building Platform WINDOWS")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
    set(PLATFORM_NAME win)
elseif(APPLE)
    message("Building Platform apple")
    set(PLATFORM_NAME apple)
elseif(UNIX)
    message("Building Platform UNIX")
    set(PLATFORM_NAME unix)
else()
    message(FATAL_ERROR "not supported Platform")
endif()

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Werror")

set(ART_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(ART_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${ART_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(libs)
add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc")
target_link_libraries(${PROJECT_NAME} Utils AppCore)

# build && copy local resource
# ******************************************************************************
set(ART_COPY_RES_CMD ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/res/qml
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/qml)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${ART_COPY_RES_CMD})
add_custom_target(CopyResources ALL COMMAND ${ART_COPY_RES_CMD})

qt5_use_modules(${PROJECT_NAME} Core Quick Widgets)

