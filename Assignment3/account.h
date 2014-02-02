#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

typedef struct
{
  char* owner;
  char* number;
  double balance;
} account;

/*********************************************************
preconditions: 
 owner is not NULL and has at least 1 character
 account_number not NULL, has at least 1 character, all characters are digits
 balance must be non-negative
postcondition: account points to new bank account
returns : NULL if any precondition is false
*/
account* create_account (char* account_owner, char* account_number, double account_balance);

/*********************************************************
precondition: acnt is not NULL
does nothing if input pointer is NULL
*/
void display_account (account* acc);

/*********************************************************
preconditions:
 acnt is not NULL
 deposit must be positive
postcondition: deposit has been added to balance

returns: 0 if any input is not valid - 1 otherwise
*/
int deposit (account* acv, double account_deposit);

/*********************************************************
preconditions:
 acnt is not NULL
 withdrawl must be positive & cannot be greater than balance
postcondition: amount has been subtracted from balance
returns: 0 if any input is not valid - 1 otherwise
*/
int withdraw (account* acc, double account_withdraw);

/*********************************************************
preconditions: acnt is a pointer to bank account 
postcondition: all memory allocated to the bank account has been deallocated
*/
void delete_account (account* acc);

#endif
