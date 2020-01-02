CC=clang++ -g
CFLAGS=-I../lib/boost_1_71_0 -std=c++11
LIBS=-L../lib/boost_1_71_0/stage/lib -lboost_unit_test_framework
DYLD_LIBRARY_PATH=../lib/boost_1_71_0/stage/lib

prob2.out: prob2.o machine.o
	$(CC) $(CFLAGS) -o prob2.out prob2.o machine.o

prob2.o: prob2.cpp
	$(CC) $(CFLAGS) -c prob2.cpp

prob1.out: prob1.o machine.o
	$(CC) $(CFLAGS) -o prob1.out prob1.o machine.o

prob1.debug: prob1.cpp machine.cpp machine.h
	$(CC) $(CFLAGS) machine.cpp prob1.cpp -o prob1.out

prob1.o: prob1.cpp
	$(CC) $(CFLAGS) -c prob1.cpp -o prob1.o

machine.o: machine.cpp machine.h
	$(CC) $(CFLAGS) -c machine.cpp -o machine.o

clean:
	rm -rf *.o *.out *.dSYM
