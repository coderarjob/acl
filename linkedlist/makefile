# Builds test for the linkedlist

obj = acl_linkedlist.o main.o

ll_test: $(obj)
	gcc -Wall -o ll_test $(obj)

acl_linkedlist.o: acl_linkedlist.c acl_linkedlist.h
	gcc -Wall -c acl_linkedlist.c

main.o: main.c
	gcc -Wall -c main.c

clean: 
	rm -f *.o ll_test
