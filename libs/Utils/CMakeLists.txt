set(TARGET_NAME Utils)

FILE(GLOB_RECURSE TARGET_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.c* ${CMAKE_CURRENT_SOURCE_DIR}/*.h* ${ART_INCLUDE_DIR}/${TARGET_NAME}/*.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=date-time")

add_library(${TARGET_NAME} STATIC ${TARGET_SRC})
qt5_use_modules(${TARGET_NAME} Quick)
