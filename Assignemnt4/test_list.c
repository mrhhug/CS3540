#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void display_list(list* l);

int main()
{
	list* l = create_list();
	append(l, "def");
	prepend(l, "abc");
	insert_in_list(l, 1, "mmm");
	append(l, "ghi");
	append(l, "jkl");
	display_list(l);
	printf("\n");
	set(l, 0, "www");
	display_list(l);
	printf("\n");
	set(l, 4, "qqq");
	display_list(l);
	printf("\n");
	delete_from_list(l, 4);
	delete_from_list(l, 0);
	display_list(l);
	printf("\n");
	insert_in_list(l, 1, "abc");
	insert_in_list(l, 3, "g-.5");
	display_list(l);
	printf("\n");
	set(l, 3, "fff");
	display_list(l);
	printf("\n");
	return 0;
}

void display_list(list* l)
{
	if (l == NULL)
		printf("null list\n");
	else
	{
		int i;
		for (i = 0; i < l -> size; i++)
		{
			char* data = (char*) get(l, i);
			printf("%s\n", data);
		}
	}
}
