CC=clang++
CFLAGS=-I../lib/boost_1_71_0 -std=c++11
LIBS=-L../lib/boost_1_71_0/stage/lib -lboost_unit_test_framework
DYLD_LIBRARY_PATH=../lib/boost_1_71_0/stage/lib
SRC_PATH=src
OBJ_PATH=obj

prob1.out: prob1.o machine.o
	$(CC) $(CFLAGS) ${LIBS} -o ${OBJ_PATH}/prob1.out ${OBJ_PATH}/prob1.o ${OBJ_PATH}/machine.o

prob1.o:
	$(CC) $(CFLAGS) -c ${SRC_PATH}/prob1.cpp -o ${OBJ_PATH}/prob1.o

machine.o: src/machine.cpp src/machine.h
	$(CC) $(CFLAGS) -c ${SRC_PATH}/machine.cpp -o ${OBJ_PATH}/machine.o

clean:
	rm -rf obj/*
