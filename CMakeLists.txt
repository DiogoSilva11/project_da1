cmake_minimum_required(VERSION 3.17)
project(P1_DA)

# Build the Google tests
set(GOOGLETEST_PATH lib/googletest-master)
add_subdirectory(${GOOGLETEST_PATH})

# Source files
file(GLOB Classes_FILES CONFIGURE_DEPENDS "Classes/*.cpp")

add_executable(Classes main.cpp ${Classes_FILES})

target_link_libraries(Classes gtest_main gmock_main)