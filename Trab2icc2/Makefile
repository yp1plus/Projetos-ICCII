all: exec

run:
	./exec

clean: 
	rm  *.o
	rm exec

zip:
	zip icc2Trabalho2.zip *

exec: hash.o main.o
	gcc -o exec hash.o main.o

main.o: main.c
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c