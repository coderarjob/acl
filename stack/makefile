
bin/acl_stack.a: bin/acl_stack.o 
	ar rcs bin/acl_stack.a bin/acl_stack.o

bin/acl_stack.o: acl_stack.c acl_stack.h
	gcc -g -c acl_stack.c -o bin/acl_stack.o

clean: 
	rm -f bin/*.o bin/*.a
