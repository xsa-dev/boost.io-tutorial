cmake_minimum_required(VERSION 3.10)
project(Tutorial)

FIND_PACKAGE( Boost 1.76 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

ADD_EXECUTABLE( Tutorial timer.cpp)

TARGET_LINK_LIBRARIES( Tutorial LINK_PUBLIC ${Boost_LIBRARIES} )