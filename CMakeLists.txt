# Written in 2012 by Ruben Van Boxem <vanboxem.ruben@gmail.com>
#
# To the extent possible under law, the author(s) have dedicated all copyright and related
# and neighboring rights to this software to the public domain worldwide. This software is
# distributed without any warranty.
#
# You should have received a copy of the CC0 Public Domain Dedication along with this software.
# If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.


cmake_minimum_required (VERSION 2.8)

project(Twist)
if(CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

# Boost
find_package(Boost REQUIRED)

# Compiler
file(GLOB compiler_source compiler/*.c++)
file(GLOB compiler_headers compiler/*.h++)
include_directories(${CTwist_SOURCE_DIR}/compiler ${Boost_INCLUDE_DIR})
add_executable(twist ${compiler_source} ${compiler_headers})
target_link_libraries(twist ${Boost_LIBRARIES})

# runtime - built with new compiler

# tests
