test_list: linked_list.o test_list.o
	gcc -g -o test_list test_list.o linked_list.o
	
linked_list.o: linked_list.h linked_list.c
	gcc -g -Wall -c linked_list.c

test_list.o: linked_list.h test_list.c
	gcc -g -Wall -c test_list.c

clean:
	rm -f linked_list.o test_list.o test_list
