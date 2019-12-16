CC=clang -g
CXX=clang++ -g
prob2.out: moon.o prob2.o
	$(CXX) -std=c++11 prob2.o moon.o -o prob2.out

prob1.out: moon.o prob1.o
	$(CC) moon.o prob1.o -o prob1.out

prob1.o: prob1.c
	$(CC) -c prob1.c

prob2.o: prob2.cpp
	$(CXX) -std=c++11 -c prob2.cpp

moon.o: moon.h moon.c
	$(CC) -c moon.c

clean:
	rm -rf *.o *.out *.dSYM
