cmake_minimum_required(VERSION 3.8)
project(M2OEP)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp Rentals.cpp Rentals.h Motorboat.cpp Motorboat.h Pontoon.cpp Pontoon.h)
add_executable(testingProject testing.cpp Rentals.cpp Rentals.h Motorboat.cpp Motorboat.h Pontoon.cpp Pontoon.h)