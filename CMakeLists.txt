cmake_minimum_required (VERSION 2.6)
project (view)
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

find_package( OpenCV REQUIRED )

add_executable (view src/main.cpp)
target_link_libraries (view tisys tiobj ${OpenCV_LIBS})

install(TARGETS view DESTINATION bin)
