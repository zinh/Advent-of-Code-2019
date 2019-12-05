all: prob2 prob1

prob1: prob1.c
	clang prob1.c -o prob1.out

prob2: prob2.c
	clang prob2.c -o prob2.out

prob2.debug: prob2.c
	clang -g prob2.c -o prob2.out

clean:
	rm -rf *.out *.out.dSYM
