#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct list_node
{
  void* item;
  struct list_node* next;
} node;

typedef struct
{
  node* front;
  node* rear;
  int size;
} list;

/*************************
return empty list
*/
list* create_list();

/***************************************************
precondition: l is not NULL - verified with assertion
return whether list is empty
*/
int is_empty (list* l);

/***************************************************
precondition: l is not NULL - verified with assertion
return size of list
*/
int size (list* l);

/****************************************************
precondition: l is not NULL - verified with assertion
postcondition: all memory allocated to l has been deallocated
*/
void delete (list* l);

/*****************************************************
precondition: l is not NULL - verified with assertion
postcondition: item has been appended to l
*/
void append (list* l, void* item);

/****************************************************
precondition: l is not NULL - verified with assertion
postcondition: item has been prepended to l
*/
void prepend (list* l, void* item);

/*****************************************************
precondition:
l is not NULL - checked by assertion
0 <= location <= size of list
return whether insertion was performed - not performed if location
is not valid
*/

int insert_in_list (list* l, int location, void* item);

/******************************************************
precondition:
l is not NULL - checked by assertion
0 <= location < size of list
return whether deletion was performed - not performed if location
is not valid
*/
int delete_from_list (list*l, int location);

/***********************************************
precondition:
l is not NULL - checked by assertion
0 <= location < size of list
return element at index location - NULL is location
is not valid
*/
void* get (list* l, int location);

/****************************************************
precondition:
l is not NULL - checked by assertion
0 <= location < size of list
postcondition: item is at index index in l
return whether operation was successful - not
successful if location is not valid
*/
int set (list* l, int location, void* item);

#endif
