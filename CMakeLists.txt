cmake_minimum_required(VERSION 3.0.0)
project(Cpp-Test VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

file (GLOB_RECURSE SOURCE_FILE CONFIGURE_DEPENDS "Source/**/*.cpp")
file (GLOB_RECURSE SOURCE_FIL CONFIGURE_DEPENDS "Source/*.cpp")
file (GLOB_RECURSE INCLUDE_FILE CONFIGURE_DEPENDS "Include/**/*.hpp")

set (INCLUDE_DIR "")
foreach (_headerFile ${INCLUDE_FILE})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIR ${_dir})
endforeach()
list (REMOVE_DUPLICATES INCLUDE_DIR)

add_executable(Test main.cpp ${SOURCE_FILE} ${SOURCE_FIL})
target_include_directories(Test PUBLIC ${INCLUDE_DIR})
