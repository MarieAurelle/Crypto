all : Programme

Programme : main.o chiffrement.o conversion.o
	$ gcc -o Programme main.o chiffrement.o conversion.o -lm
# ici on fait l'édition de lien entre tous les fichiers en .o

main.o : chiffrement.o chiffrement.h main.c
	$ gcc -Wall -c main.c -o main.o
 
chiffrement.o : conversion.o conversion.h chiffrement.c
	$ gcc -Wall -c chiffrement.c -o chiffrement.o

conversion.o : conversion.c
	$ gcc -Wall -c conversion.c -o conversion.o 

clean :
	-rm Programme
