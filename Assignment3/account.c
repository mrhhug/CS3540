/*
 *Author : Michael Hug
 *Author email : hmichae4@students.kennesaw.edu
 *Student of Prof Gayler cs3540 Spr014
 *Assignment 3 - implement a bank account
 *run like: "make && ./test_account"
 */
#include "account.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int is_valid_account_owner (char* o)
{
    return o != NULL && strlen (o) > 0;
}

int is_valid_account_number (char* n)
{
    int result = n != NULL && strlen (n) > 0;
    if (result)
    {
        int i = 0;
        while (isdigit (n[i]))
            i++;
        result = i == strlen (n);
    }
    return result;
}

int is_valid_account_balance (double b)
{
    return b > 0;
}

account* create_account (char* account_owner, char* account_number, double account_balance)
{
    account* a = NULL;
    if (is_valid_account_owner (account_owner) && is_valid_account_number (account_number) 
      && is_valid_account_balance (account_balance))
    {
        a = malloc (sizeof(account));
        a -> owner = malloc ((strlen (account_owner) + 1) * sizeof(char));
        strcpy (a -> owner, account_owner);
        a -> number = malloc ((strlen (account_number) + 1) * sizeof(char));
        strcpy (a -> number, account_number);
        a -> balance = account_balance;
    }
    return a;
}

void display_account (account* acc)
{
    if (acc != NULL)
    {
        printf ("Account owner: %s\n", acc -> owner);
        printf ("Account number: %s\n", acc -> number);
        printf ("Account balance: %g\n", acc -> balance);
    }
}

int deposit (account* acc, double account_deposit)
{
    int returnme = 0;
    if (acc != NULL && account_deposit > 0)
    {
        returnme = 1;
        acc -> balance += account_deposit;
    }
    return returnme;
}

int withdraw (account* acc, double account_withdraw)
{
    int returnme = 0;
    if (acc != NULL && account_withdraw > 0 && acc -> balance >= account_withdraw)
    {
        returnme = 1;
        acc -> balance -= account_withdraw;
    }
    return returnme;
}

void delete_account (account* acc)
{
    if (acc != NULL)
    {
        if (acc -> owner != NULL)
          free (acc -> owner);
        if (acc -> number != NULL)
          free (acc -> number);
        free (acc);
    }
}
