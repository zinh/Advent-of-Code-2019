CC=clang
prob1: rule.o prob1.c
	$(CC) prob1.c rule.o

rule.o: rule.c rule.h
	$(CC) -c rule.c

clean:
	rm -rf *.o *.out
