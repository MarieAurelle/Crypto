#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define taille_msg_hexa 16
#define taille_cle_hexa 20
char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

/*Cette fonction prend en entrée le chiffre hexa qu'elle doit convertir
 * le tableau où elle doit écrire le résultat
 * l'endroit du tableau résultat où elle doit commencer à écrire */
void conversion_binaire(char hexa, int binaire[4], int deb){

	switch(hexa){
			
		case '0':
		binaire[deb] = 0;
		binaire[deb+1] = 0;
		binaire[deb+2] = 0;
		binaire[deb+3] = 0;
		break;
		
		case '1':
		binaire[deb] = 0;
		binaire[deb+1] = 0;
		binaire[deb+2] = 0;
		binaire[deb+3] = 1;
		break;
		
		case '2':
		binaire[deb] = 0;
		binaire[deb+1] = 0;
		binaire[deb+2] = 1;
		binaire[deb+3] = 0;
		break;
		
		case '3':
		binaire[deb] = 0;
		binaire[deb+1] = 0;
		binaire[deb+2] = 1;
		binaire[deb+3] = 1;
		break;
		
		case '4':
		binaire[deb] = 0;
		binaire[deb+1] = 1;
		binaire[deb+2] = 0;
		binaire[deb+3] = 0;
		break;
		
		case '5':
		binaire[deb] = 0;
		binaire[deb+1] = 1;
		binaire[deb+2] = 0;
		binaire[deb+3] = 1;
		break;
		
		case '6':
		binaire[deb] = 0;
		binaire[deb+1] = 1;
		binaire[deb+2] = 1;
		binaire[deb+3] = 0;
		break;
		
		case '7':
		binaire[deb] = 0;
		binaire[deb+1] = 1;
		binaire[deb+2] = 1;
		binaire[deb+3] = 1;
		break;
		
		case '8':
		binaire[deb] = 1;
		binaire[deb+1] = 0;
		binaire[deb+2] = 0;
		binaire[deb+3] = 0;
		break;
		
		case '9':
		binaire[deb] = 1;
		binaire[deb+1] = 0;
		binaire[deb+2] = 0;
		binaire[deb+3] = 1;
		break;
		
		case 'a':
		binaire[deb] = 1;
		binaire[deb+1] = 0;
		binaire[deb+2] = 1;
		binaire[deb+3] = 0;
		break;
		
		case 'b':
		binaire[deb] = 1;
		binaire[deb+1] = 0;
		binaire[deb+2] = 1;
		binaire[deb+3] = 1;
		break;
		
		case 'c':
		binaire[deb] = 1;
		binaire[deb+1] = 1;
		binaire[deb+2] = 0;
		binaire[deb+3] = 0;
		break;
		
		case 'd':
		binaire[deb] = 1;
		binaire[deb+1] = 1;
		binaire[deb+2] = 0;
		binaire[deb+3] = 1;
		break;
		
		case 'e':
		binaire[deb] = 1;
		binaire[deb+1] = 1;
		binaire[deb+2] = 1;
		binaire[deb+3] = 0;
		break;
		
		case 'f':
		binaire[deb] = 1;
		binaire[deb+1] = 1;
		binaire[deb+2] = 1;
		binaire[deb+3] = 1;
		break;
		
		default:
		printf("Ce n'est pas un hexadecimal\n");
		break;
	}
}

/* Cette fonction prend en entrée un nombre binaire
 * calcule sa forme en décimal et s'en sert pour trouver
 * la notation héxadécimale dans le tableau hexa[]
 * qui contient tous les nombres hexadécimal en fonction de leur valeur décimale
 * (qui est égale à leur place dans le tableau) et renvoie la bonne valeur*/
char conversion_hexadecimal(int bin[4]){
	int decimal=0, p=0, i;
	
	for(i=3; i>=0; i--){
		decimal = decimal + bin[i]*pow(2,p);
		p++;
	}

	return hexa[decimal];
}
