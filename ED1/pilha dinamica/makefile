all: teste

teste: main.o pilha.o
	gcc -o teste main.o pilha.o

main.o: main.c pilha.h
	gcc -c main.c -Wall

pilha.o: pilha.c pilha.h
	gcc -c pilha.c -Wall

clean:
	rm main.o pilha.o teste