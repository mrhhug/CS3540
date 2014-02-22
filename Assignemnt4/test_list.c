#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void display_list (list* l);

int main ()
{
  list* l = create_list();
  append (l, "abc");
  append (l, "def");
  prepend (l, "xyz");
  insert_in_list (l, 1, "mmm");
  display_list (l);
  printf ("\n");
  set (l, 1, "www");
  display_list(l);
  return 0;
}

void display_list (list* l)
{
  if (l == NULL)
    printf ("null list\n");
  else
  {
    int i;
    for (i = l -> size; i > 0 ; i--)
    {
      char* data = (char*)get (l, i);
      printf ("%s\n", data);
    }
  }
}
