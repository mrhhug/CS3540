#include "linked_list.h"
#include <stdlib.h>
#include <assert.h>

node* create_node (void* item)
{
  node* n = malloc (sizeof(node));
  n -> item = item;
  n -> next = NULL;
  n -> prior = NULL;
  return n;
}
 
list* create_list()
{
  list* l = malloc (sizeof(list));
  l -> size = 0;
  l -> front = NULL;
  l -> rear = NULL;
  return l;
}

int is_empty (list* l)
{
  assert (l != NULL);
  return l -> size == 0;
}

int size (list* l)
{
  assert (l != NULL);
  return l -> size;
}

void delete (list* l)
{
  assert (l != NULL);
  node* current = l -> front;
  while (current != NULL)
  {
    node* temp = current -> next;
    free (current);
    current = temp;
  }
  free (l);
}

void append (list* l, void* item)
{
  assert (l != NULL);
  if (is_empty (l))
  {
    l -> front = create_node (item);
    l -> rear = l -> front;
  }
  else
  {
  	node* new = create_node (item);
	l -> rear -> next = new;
	new -> prior = l -> rear;
    l -> rear = l -> rear -> next;
  }
  l -> size++;
}

void prepend (list* l, void* item)
{
  assert (l != NULL);
  if (is_empty (l))
  {
    l -> front = create_node (item);
    l -> rear = l -> front;
  }
  else
  {
  	node* new = create_node (item);
    new -> next = l -> front;
    l -> front -> prior = new;
    l -> front = new;
  }
  l -> size++;
}

int insert_in_list (list* l, int location, void* item)
{
  assert (l != NULL);
  int result = 0 <= location && location <= size(l);
  if (result)
  {
    if (location == 0)
      prepend (l, item);
    else if (location == size(l))
      append (l, item);
    else
    {
      node* current = l -> front;
      int i = 0;
      while (i < location - 1)
      {
	current = current -> next;
	i++;
      }
      node* temp = create_node (item);
      temp -> next = current -> next;
      current -> next = temp;
    }
    l -> size++;
  }
  return result;
  
}

int delete_from_list (list*l, int location)
{
  assert (l != NULL);
  int result = 0 <= location && location < size(l);
  if (result)
  {
    node* temp;
    if (location == 0)
    {
      temp = l -> front;
      l -> front = l -> front -> next;
      if (size(l) == 1)
	l -> rear = NULL;
    }
    else
    {
      node* current = l -> front;
      int i = 0;
      while (i < location - 1)
      {
	current = current -> next;
	i++;
      }
      temp = current -> next;
      current -> next = temp -> next;
      if (location == size(l) - 1)
	  l -> rear = current;
    }
    free (temp);
    l -> size--;
  }
  return result;
}

void* get (list* l, int location)
{
  assert (l != NULL);
  void* result = NULL;
  if (0 <= location && location < size(l))
  {
    node* current = l -> front;
    int i = 0;
    while (i < location)
    {
      current = current -> next;
      i++;
    }
    result = current -> item;
  }
  return result;
}

int set (list* l, int location, void* item)
{
  assert (l != NULL);
  int result = 0 <= location && location < size(l);
  if (result)
  {
    node* current = l -> front;
    int i = 0;
    while (i < location)
    {
      current = current -> next;
      i++;
    }
   current -> item = item;
  }
  return result;
}
