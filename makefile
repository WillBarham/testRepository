#A makefile to create my project’s executable.

OBJS = driver.o FinalProject.o Heap.o Sort.o TreeSort.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) #Flags for compiling object files
LFLAGS = -Wall $(DEBUG)    #Flags for linking

FinalProjectCSCI2270 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o FinalProjectCSCI2270

driver.o : FinalProject.h
	$(CC) $(CFLAGS) driver.cpp

FinalProject.o : Sort.h Heap.h TreeSort.h FinalProject.h
	$(CC) $(CFLAGS) FinalProject.cpp

Heap.o : Heap.h
	$(CC) $(CFLAGS) Heap.cpp

Sort.o : Sort.h
	$(CC) $(CFLAGS) Sort.cpp

TreeSort.o : TreeSort.h
	$(CC) $(CFLAGS) TreeSort.cpp

clean:
	\rm *.o *~ FinalProjectCSCI2270