all: teste

teste: main.o fila.o
	gcc -o teste main.o fila.o

main.o: main.c fila.h
	gcc -c main.c -Wall

fila.o: fila.c fila.h
	gcc -c fila.c -Wall

clean:
	rm main.o fila.o teste