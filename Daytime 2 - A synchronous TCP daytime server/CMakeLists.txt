cmake_minimum_required(VERSION 3.10)
project(server)

FIND_PACKAGE( Boost 1.76 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

ADD_EXECUTABLE( server server.cpp)

TARGET_LINK_LIBRARIES( server LINK_PUBLIC ${Boost_LIBRARIES} )