prob2.out: moon.o prob2.o
	clang++ -std=c++11 prob2.o moon.o -o prob2.out

prob1.out: moon.o prob1.o
	clang moon.o prob1.o -o prob1.out

prob1.o: prob1.c
	clang -c prob1.c

prob2.o: prob2.cpp
	clang++ -std=c++11 -c prob2.cpp

moon.o: moon.h moon.c
	clang -c moon.c

clean:
	rm -rf *.o *.out
