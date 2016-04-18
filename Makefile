all : Programme

Programme : main.o chiffrement.o conversion.o
	$ gcc -o Programme main.o chiffrement.o conversion.o 
# ici on fait lédition de lien entre tous les fichiers en .o

main.o : main.c chiffrement.h
	$ gcc -Wall -c main.c -o main.o
 
chiffrement.o : chiffrement.c conversion.h
	$ gcc -c chiffrement.c -o chiffrement.o

conversion.o : conversion.c
	$ gcc -c conversion.c -o conversion.o

clean :
	-rm Programme
