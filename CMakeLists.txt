cmake_minimum_required(VERSION 3.0.0)
project(LibrarySystemCpp VERSION 0.1.0)

include(CTest)
enable_testing()
file(GLOB helloworld_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")
add_executable(LibrarySystemCpp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
if(NOT EXISTS ${PROJECT_BINARY_DIR}/.gitignore)
    file(WRITE ${PROJECT_BINARY_DIR}/.gitignore "*")
endif()