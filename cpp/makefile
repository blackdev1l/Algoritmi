CC = g++
C_FLAGS = -Wall
OBJECTS = algoritmi.o main.o

main: main.o algoritmi.o 

main.o: main.cpp algoritmi.h
	$(CC) $(C_FLAGS) -c main.cpp
algoritmi.o: algoritmi.cpp
	$(CC) $(C_FLAGS) -c algoritmi.cpp
.PHONY: clean
clean:
	-rm $(OBJECTS)
