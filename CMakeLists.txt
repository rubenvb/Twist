# Written in 2012 by Ruben Van Boxem <vanboxem.ruben@gmail.com>
#
# To the extent possible under law, the author(s) have dedicated all copyright and related
# and neighboring rights to this software to the public domain worldwide. This software is
# distributed without any warranty.
#
# You should have received a copy of the CC0 Public Domain Dedication along with this software.
# If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.


cmake_minimum_required (VERSION 2.6)

project(CTwist)

# Compiler
file(GLOB compiler_source compiler/*.cpp)
file(GLOB compiler_headers compiler/*.h)
include_directories(${CTwist_SOURCE_DIR}/compiler)
add_executable(ctwist ${compiler_source})


# runtime - built with new compiler

# tests
enable_testing()
set(COMPILER_TESTS "${CTwist_SOURCE_DIR}/compiler/test")
add_test("hello" ctwist 2>&1 )

