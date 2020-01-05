CC=clang++
CFLAGS=-I../lib/boost_1_71_0 -std=c++11
LIBS=-L../lib/boost_1_71_0/stage/lib -lboost_unit_test_framework
DYLD_LIBRARY_PATH=../lib/boost_1_71_0/stage/lib

all: prob1.out

prob1.out: machine.o mmu.o prob1.cpp
	$(CC) $(CFLAGS) prob1.cpp machine.o mmu.o -o prob1.out

mmu.o: mmu.h mmu.cpp
	$(CC) $(CFLAGS) -c mmu.cpp -o mmu.o

machine.o: mmu.o machine.cpp machine.h
	$(CC) $(CFLAGS) -c machine.cpp -o machine.o

mmu_test.out: mmu.o mmu_test.cpp
	$(CC) $(CFLAGS) $(LIBS) mmu.o mmu_test.cpp -o mmu_test.out

machine_test.out: machine.o machine_test.cpp
	$(CC) $(CFLAGS) $(LIBS) machine.o machine_test.cpp -o machine_test.out

test: machine_test.out
	DYLD_LIBRARY_PATH=../lib/boost_1_71_0/stage/lib ./machine_test.out

clean:
	rm -rf *.o *.out *.dSYM
