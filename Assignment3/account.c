#include "account.h"

account* create_account (char* account_owner, char* account_number, double account_balance)
{
    account* a = NULL;
    if (is_valid_account_owner (account_owner) && is_valid_account_number (account_number) 
      && is_valid_account_balance (account_balance)
    {
        a = malloc (sizeof(account));
        a -> owner = malloc ((strlen (account_owner) + 1) * sizeof(char));
        strcpy (a -> owner, account_owner);
        s -> number = malloc ((strlen (account_number) + 1) * sizeof(char));
        strcpy (a -> number, account_number);
        s -> balance = account_balance;
    }
    return a;
}

void display_account (account* acc)
{
    if (acc != NULL)
    {
        printf ("Owner: %s\n", acc -> owner);
        printf ("Number: %s\n", acc -> number);
        printf ("Balance: %f\n", acc -> balance);
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
    if (acc != NULL && account_withdraw > 0 && acc -> balanc <= account_withdraw)
    {
        returnme = 1;
        acc -> balance = account_withdraw;
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
        if (acc -> balance)
          free (acc -> balance);
        free (acc);
    }
}
