#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

typedef struct
{
  char* owner;
  char* account_number;
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
account* create_account (char* owner, char* account_number, double balance);

/*********************************************************
precondition: acnt is not NULL
does nothing if input pointer is NULL
*/
void display_account (account* acnt);

/*********************************************************
preconditions:
 acnt is not NULL
 deposit must be positive
postcondition: deposit has been added to balance

returns: 0 if any input is not valid - 1 otherwise
*/
double deposit (account* acnt, double deposit);

/*********************************************************
preconditions:
 acnt is not NULL
 withdrawl must be positive & cannot be greater than balance
postcondition: amount has been subtracted from balance
returns: 0 if any input is not valid - 1 otherwise
*/
double withdraw (account* acnt, double withdraw);

/*********************************************************
preconditions: acnt is a pointer to bank account 
postcondition: all memory allocated to the bank account has been deallocated
*/
void delete_account (account* acnt);

#endif
