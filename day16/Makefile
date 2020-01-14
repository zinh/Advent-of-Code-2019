UNITY_ROOT=../lib/Unity-master
SRC_FILES=$(UNITY_ROOT)/src/unity.c test/TestProb1.c test/test_runners/TestProb1_Runner.c lib.c
INC_DIRS=-I. -I$(UNITY_ROOT)/src
C_COMPILER=clang
CFLAGS=

all: clean default

prob2.out: prob2.c lib.c
	$(C_COMPILER) $(CFLAGS) prob2.c lib.c -o prob2.out

prob1.out: prob1.c lib.c
	$(C_COMPILER) $(CFLAGS) prob1.c lib.c -o prob1.out

default: $(SRC_FILES)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES) -o test.out
	- ./test.out

test/test_runners/TestFFT_Runner.c: test/TestFFT.c
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb test/TestFFT.c  test/test_runners/TestFFT_Runner.c

test/test_runners/TestProb1_Runner.c: test/TestProb1.c
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb test/TestProb1.c  test/test_runners/TestProb1_Runner.c

clean:
	rm -rf *.out *.out.dSYM
