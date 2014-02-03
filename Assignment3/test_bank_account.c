/*
 *Author : Michael Hug
 *Author email : hmichae4@students.kennesaw.edu
 *Student of Prof Gayler cs3540 Spr014
 *Assignment 3 - implement a bank account
 *run like: "make && ./test_account"
 */
#include "bank_account.h"
#include <stdio.h>

int main ()
{
	account* a = create_account ("Michael", "1", 5);
    account* b = create_account (NULL, "1", 5);
    if (b == NULL)
    	printf ("good null on test case b\n");
    account* c = create_account ("", "1", 5);
    if (c == NULL)
    	printf ("good null on test case c\n");
    account* d = create_account ("Michael", NULL, 5);
    if (d == NULL)
    	printf ("good null on test case d\n");
    account* e = create_account ("Michael", "", 5);
    if (e == NULL)
    	printf ("good null on test case e\n");
    account* f = create_account ("Michael", "d", 5);
    if (f == NULL)
    	printf ("good null on test case f\n");
    account* g = create_account ("Michael", "1", 0);
    if (g == NULL)
    	printf ("good null on test case g\n");
    account* h = create_account ("Michael", "e", 0);
    if (h == NULL)
    	printf ("good null on test case h\n");
    display_account (NULL);
    printf ("bad deposit (null pointer): %d\n", deposit(NULL,0));
    printf ("bad deposit (non-positve deposit - 0): %d\n", deposit(a,0));
    printf ("good deposit (2): %d\n", deposit(a,2));
    printf ("bad withdraw (null pointer): %d\n", withdraw(NULL,0));
    printf ("bad withdraw (non-positve withdraw - 0): %d\n", withdraw(a,0));
    printf ("bad withdraw (insufficient balance - 8): %d\n", withdraw(a,8));
    printf ("good withdraw (3): %d\n", withdraw(a,3));
    display_account (a);
    delete_account (a);
    delete_account (NULL);
    return 0;
}
