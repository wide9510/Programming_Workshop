CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: test

main: main.cpp Counter.hpp
	$(CXX)	$(CXXFLAGS)	main.cpp  -o main

test: test.cpp Counter.hpp
	$(CXX)	$(CXXFLAGS)	test.cpp  -o test

clean:
	rm test main