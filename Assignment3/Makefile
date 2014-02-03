#!/usr/bin/make -f
#Author : Michael Hug
#Author email : hmichae4@students.kennesaw.edu
#Student of Prof Gayler cs3540 Spr014
#Assignment 3 - implement a bank account
#run like: "make && ./test_account"
test_bank_account: bank_account.o test_bank_account.o
	gcc -o test_bank_account bank_account.o test_bank_account.o

bank_account.o: bank_account.c bank_account.h
	gcc -g -Wall -c bank_account.c

test_bank_account.o: test_bank_account.c bank_account.h
	gcc -g -Wall -c test_bank_account.c

clean:
	rm -f bank_account.o test_bank_account.o test_bank_account
