cmake_minimum_required(VERSION 2.8.11)
project(cpp_otp)
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

configure_file(CMakeLists.txt.in2 googlefruit-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googlefruit-download )
if(result)
    message(FATAL_ERROR "CMake step for googlefruit failed: ${result}")
endif()

set(FRUIT_USES_BOOST false)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googlefruit-download )
if(result)
    message(FATAL_ERROR "Build step for googlefruit failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()
add_subdirectory(${CMAKE_BINARY_DIR}/googlefruit-src
        ${CMAKE_BINARY_DIR}/googlefruit-build
        EXCLUDE_FROM_ALL)
include_directories("${CMAKE_BINARY_DIR}/googlefruit-src/include")
include_directories("${CMAKE_BINARY_DIR}/googlefruit-build/include")

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(main)
add_subdirectory(test)
