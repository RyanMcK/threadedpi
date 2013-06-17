cmake_minimum_required(VERSION 2.8)

project(threadedpi)

include_directories(include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Boost COMPONENTS program_options unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_definitions(-std=c++11 -O3)
add_executable(threadedpi src/threadedpi.cpp src/pisimulation.cpp)
target_link_libraries(threadedpi ${Boost_LIBRARIES})

enable_testing()
add_executable(test_threadedpi test/test_threadedpi.cpp src/pisimulation.cpp)
target_link_libraries(test_threadedpi ${Boost_LIBRARIES})
add_test(test_threadedpi bin/test_threadedpi)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)
