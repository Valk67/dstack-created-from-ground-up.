calc: calc.o dstack.o
	g++ -Wall -pedantic -g -std=c++11 -o calc calc.o dstack.o

calc.o: dstack.h calc.cpp
	g++ -Wall -pedantic -g -std=c++11 -c calc.cpp

dstack.o: dstack.h dstack.cpp
	g++ -Wall -pedantic -g -std=c++11 -c dstack.cpp


