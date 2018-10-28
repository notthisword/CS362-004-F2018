######################
# Britany Hughes
# 28 October 2018
# testme.c makefile
######################

CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: runme

testme: 
	gcc -Wall -std=c99 testme.c -o testme $(CFLAGS)

debug: testme
	./testme.exe &> results.out
	gcov testme.c >> results.out
	cat testme.c.gcov >> results.out

runme: testme
	gcc -Wall -std=c99 testme.c -o testme $(CFLAGS)
	./testme.exe
	
clean: 
	rm testme
	
cleanall: 
	rm testme testme.gcno testme.exe