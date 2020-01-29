CC = g++
FLAGS = -std=c++14 -Wall -g
OBJS = hw03ec.o

all: hw03ec

hw03ec: hw03ec.cpp
	$(CC) $(FLAGS) hw03ec.cpp -o hw03ec $(OBJS)

clean:
	rm *.o hw03ec hw03ec.tar

tar:
	tar cf hw03ec.tar hw03ec.scr makefile hw03ec.cpp