all: Programme

Programme : *.o
        gcc -o Programme main.o chiffrement.o converion.o
 
main.o : main.c chiffrement.h
        gcc -c main.c -o main.o
 
chiffrement.o : chiffrement.c conversion.h
        gcc -c chiffrement.c -o chiffrement.o

conversion.o : conversion.c
		gcc -c conversion.c -o conversion.o

clean :
		-rm Programme
