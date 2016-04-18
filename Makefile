all : Programme

Programme : main.o
	$ gcc -o Programme main.o chiffrement.o conversion.o -lm
# ici on fait l'édition de lien entre tous les fichiers en .o

main.o : chiffrement.o main.c chiffrement.h
	$ gcc -Wall -c main.c -o main.o
 
chiffrement.o : conversion .o chiffrement.c conversion.h
	$ gcc -Wall -c chiffrement.c -o chiffrement.o

conversion.o : conversion.c
	$ gcc -Wall -c conversion.c -o conversion.o 

clean :
	-rm Programme
