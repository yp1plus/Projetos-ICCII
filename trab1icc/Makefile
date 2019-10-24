all: exec

run:
	./exec

clean: 
	rm bin/*.o
	rm exec

exec: bin/horario.o bin/celula.o bin/lista.o bin/main.o
	gcc -o exec bin/horario.o bin/celula.o bin/lista.o bin/main.o

bin/main.o: main.c
	gcc -c main.c
	mv main.o bin

bin/lista.o: src/lista.c
	gcc -c src/lista.c
	mv lista.o bin

bin/celula.o: src/celula.c
	gcc -c src/celula.c
	mv celula.o bin

bin/horario.o: src/horario.c
	gcc -c src/horario.c
	mv horario.o bin