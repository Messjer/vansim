cmake_minimum_required(VERSION 3.6)
project(vansim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    LICENSE
    README.md src/World.cpp src/World.h src/main.cpp src/Network.cpp src/Network.h src/Agent.cpp src/GossipAgent.cpp src/GossipAgent.h src/GossipSession.cpp src/GossipSession.h)

add_executable(vansim ${SOURCE_FILES})