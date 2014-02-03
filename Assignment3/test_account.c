/*
 *Author : Michael Hug
 *Author email : hmichae4@students.kennesaw.edu
 *Student of Prof Gayler cs3540 Spr014
 *Assignment 3 - implement a bank account
 *run like: "make test_account && ./test_account"
 */
#include "account.h"
#include <stdio.h>

int main ()
{
    account* a = create_account (NULL, "1", 5);
    account* b = create_account ("Michael", NULL, 5);
    account* c = create_account ("Michael", "1", 0);
    // these should not print anything
    display_account (a);
    display_account (b);
    display_account (c);
    account* d = create_account ("Michael", "1", 5);
    //display_account (d);
    printf ("bad deposit return (non-positve deposit - 0): %d\n", deposit(d,0));
    printf ("good deposit return (2): %d\n", deposit(d,2));
    printf ("bad withdraw return (non-positve withdraw - 0): %d\n", withdraw(d,0));
    printf ("bad withdraw return (insufficient balance - 8): %d\n", withdraw(d,8));
    printf ("good withdraw return (3): %d\n", withdraw(d,3));
    display_account (d);
    delete_account (d);
    //display_account (d);
    return 0;
}
