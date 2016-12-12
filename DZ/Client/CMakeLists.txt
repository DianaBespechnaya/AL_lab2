cmake_minimum_required(VERSION 3.6)
project(DZ_client_new)

include_directories(/diana/include)
link_directories(/diana/lib)

include_directories(/home/diana/libboost/boost_1_61_0/include/)
link_directories(/home/diana/libboost/boost_1_61_0/stage/lib)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(DZ_client_new ${SOURCE_FILES})

target_link_libraries(DZ_client_new
        gmp
        gmpxx
        pthread
        boost_system
        boost_thread)