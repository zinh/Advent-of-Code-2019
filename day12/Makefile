prob1: moon.o prob1.o
	clang moon.o prob1.o -o prob1

prob1.o: prob1.c
	clang -c prob1.c

moon.o: moon.h moon.c
	clang -c moon.c

clean:
	rm -rf *.o *.out prob1
