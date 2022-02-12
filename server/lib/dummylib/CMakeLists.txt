cmake_minimum_required(VERSION 3.9)
project(DummyLib
        VERSION 0.0.1
        DESCRIPTION "Just an example")

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED True)
#add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=1")

set(CMAKE_EXE_LINKER_FLAGS "-Wl,-export-dynamic,-rdynamic")

# include_directories(
# 	../../API/
# )

add_library(DummyLib SHARED
	dummylib.h
	dummylib.cc
)
