file: file.o
	cc main.c -o file
file.o: main.c
	cc -c main.c -o file.o

list_files: $(wildcard *.c)
	echo $?
clean: 
	rm -f file.o
