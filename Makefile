FILES = main.cpp Star.cpp

all:
	g++ -g -std=c++11 -o main $(FILES) -pthread -lncurses

clean:
	-rm -f *.o
	-rm -f main
