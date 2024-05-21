cmake_minimum_required(VERSION 3.9)

set(tProject "start")
project(${tProject} 
                    VERSION 1.0
                    DESCRIPTION "Relational databse on cxx"
                    LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the library subdirectory
add_subdirectory(btree)

set(tIndex "Start_Me")
add_executable(${tIndex} index.cpp)

#libs
target_link_libraries(${tIndex} PUBLIC frame)

#rest
target_compile_features(${tIndex} PUBLIC cxx_std_23)
