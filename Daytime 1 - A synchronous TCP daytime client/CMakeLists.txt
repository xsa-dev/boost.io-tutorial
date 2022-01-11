cmake_minimum_required(VERSION 3.10)
project(client)

FIND_PACKAGE( Boost 1.76 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

ADD_EXECUTABLE( client client.cpp)

TARGET_LINK_LIBRARIES( client LINK_PUBLIC ${Boost_LIBRARIES} )