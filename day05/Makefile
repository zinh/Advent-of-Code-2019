CC=clang++ -g
CFLAGS=-I../lib/boost_1_71_0
LIBS=-L../lib/boost_1_71_0/stage/lib -lboost_unit_test_framework
DYLD_LIBRARY_PATH=../lib/boost_1_71_0/stage/lib

prob1.out: prob1.o machine.o
	$(CC) $(CFLAGS) -std=c++11 -o prob1.out prob1.o machine.o

prob1.o: prob1.cpp
	$(CC) $(CFLAGS) -std=c++11 -c prob1.cpp

machine.o: machine.cpp machine.h
	$(CC) $(CFLAGS) -std=c++11 -c machine.cpp

machine.test: machine.cpp machine_test.cpp
	$(CC) $(CFLAGS) $(LIBS) -std=c++11 machine_test.cpp -o machine_test.out

test: machine.test
	DYLD_LIBRARY_PATH=../lib/boost_1_71_0/stage/lib ./machine_test.out

clean:
	rm -rf *.out *.o *.out.dSYM
