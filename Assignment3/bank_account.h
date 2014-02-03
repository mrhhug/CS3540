/*
 *Author : Michael Hug
 *Author email : hmichae4@students.kennesaw.edu
 *Student of Prof Gayler cs3540 Spr014
 *Assignment 3 - implement a bank account
 *run like: "make && ./test_account"
 */
#ifndef _BANK_ACCOUNT_H_
#define _BANK_ACCOUNT_H_

typedef struct
{
  char* owner;
  char* number;
  double balance;
} account;

/*********************************************************
preconditions: 
 account_owner is not NULL and has at least 1 character
 account_number not NULL, has at least 1 character, all characters are digits
 account_balance must be non-negative

returns : NULL if any precondition is false else returns pointer to new account 
*/
account* create_account (char* account_owner, char* account_number, double account_balance);

/*********************************************************
precondition: acc is not NULL
does nothing if input pointer is NULL
*/
void display_account (account* acc);

/*********************************************************
preconditions:
 acc is not NULL
 account_deposit must be positive
postcondition: account_deposit has been added to balance

returns: 0 if any input is not valid else returns 1
*/
int deposit (account* acc, double account_deposit);

/*********************************************************
preconditions:
 acc is not NULL
 account_withdraw must be positive & cannot be greater than balance
postcondition: account_withdraw has been subtracted from balance

returns: 0 if any input is not valid else returns 1
*/
int withdraw (account* acc, double account_withdraw);

/*********************************************************
preconditions: acc is a pointer to bank account 
postcondition: all memory allocated to the bank account has been deallocated
*/
void delete_account (account* acc);

#endif
