# This is an example make file

CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall  # flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

# runs for "make all"
all: main

# runs for "make main"
# the line below this one must be TABBED in (not spaces!)
# files Point.o and main.cpp will be monitored for changes to know if it needs to be re-made
main: pe3_references.cpp
	$(CXX)	$(CXXFLAGS)	pe3_references.cpp -o main 

# runs for "make clean"
clean:
	rm main