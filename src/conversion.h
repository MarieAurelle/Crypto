#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define taille_msg_hexa 16
#define taille_cle_hexa 20
char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
char boite_S[16] = {'b', 'f', '3', '2', 'a', 'c', '9', '1', '6', '7', '8', '0', 'e', '5', 'd', '4'};

void conversion_binaire(char hexa, int binaire[4], int deb);
void conversion_decimal(int entier, int bin[5]);
