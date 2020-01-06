CC=clang++ -g
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

frame_buffer.o: frame_buffer.cpp frame_buffer.h mmu.o
	$(CC) $(CFLAGS) -c frame_buffer.cpp -o frame_buffer.o

mmu_test.out: mmu.o mmu_test.cpp
	$(CC) $(CFLAGS) $(LIBS) mmu.o mmu_test.cpp -o mmu_test.out

machine_test.out: machine.o machine_test.cpp
	$(CC) $(CFLAGS) $(LIBS) machine.o machine_test.cpp -o machine_test.out

frame_buffer_test.out: frame_buffer_test.cpp frame_buffer.o
	$(CC) $(CFLAGS) $(LIBS) frame_buffer_test.cpp frame_buffer.o -o frame_buffer_test.out

test_frame_buffer:
	DYLD_LIBRARY_PATH=../lib/boost_1_71_0/stage/lib ./frame_buffer_test.out

test_machine: machine_test.out
	DYLD_LIBRARY_PATH=../lib/boost_1_71_0/stage/lib ./machine_test.out

test_mmu: mmu_test.out
	DYLD_LIBRARY_PATH=../lib/boost_1_71_0/stage/lib ./mmu_test.out

test_all: test_machine test_mmu test_frame_buffer

clean:
	rm -rf *.o *.out *.dSYM
