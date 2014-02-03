#!/usr/bin/make -f
#Author : Michael Hug
#Author email : hmichae4@students.kennesaw.edu
#Student of Prof Gayler cs3540 Spr014
#Assignment 3 - implement a bank account
#run like: "make && ./test_account"
test_account: account.o test_account.o
	gcc -o test_account account.o test_account.o

account.o: account.c account.h
	gcc -g -Wall -c account.c

test_account.o: test_account.c account.h
	gcc -g -Wall -c test_account.c

clean:
	rm -f account.o test_account.o test_account
