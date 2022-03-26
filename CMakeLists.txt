cmake_minimum_required(VERSION 3.0.0)
project(LibrarySystemCpp VERSION 0.1.0)

include(CTest)

enable_testing()
file(GLOB_RECURSE LibrarySystemCpp_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")
file(GLOB_RECURSE REMOVE_CMAKE "build/*")
list(REMOVE_ITEM LibrarySystemCpp_SRC ${REMOVE_CMAKE})
add_executable(LibrarySystemCpp ${LibrarySystemCpp_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# if(NOT EXISTS ${PROJECT_BINARY_DIR}/.gitignore)
#     file(WRITE ${PROJECT_BINARY_DIR}/.gitignore "*")
# endif()