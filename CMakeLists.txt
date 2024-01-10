cmake_minimum_required(VERSION 3.26)
project(DSA_proj1)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA_proj1 main.cpp
        Athlete.cpp
        Base.h
        Score.cpp
        Column.cpp
        Manager.cpp
        Athlete.h
        Column.h
        Manager.h
        Score.h)
