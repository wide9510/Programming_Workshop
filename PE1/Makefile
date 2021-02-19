# This is an example make file

CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall  # flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

# runs for "make all"
all: main

# runs for "make main"
# the line below this one must be TABBED in (not spaces!)
# files Point.o and main.cpp will be monitored for changes to know if it needs to be re-made
main: Point.o main.cpp
	$(CXX)	$(CXXFLAGS)	main.cpp Point.o -o main 

Point.o: Point.h
	$(CXX)	$(CXXFLAGS) -c Point.cpp

# runs for "make clean"
clean:
	rm Point.o main