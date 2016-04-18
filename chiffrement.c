#include "conversion.h"
char boite_S[16] = {'b', 'f', '3', '2', 'a', 'c', '9', '1', '6', '7', '8', '0', 'e', '5', 'd', '4'};

/* Cette fonction prend en entrée un tableau contenant le nombre binaire à modifier
 * calcule sa valeur décimale pour aller chercher sa nouvelle valeur dans le tableau boite_S
 * trouve sa nouvelle valeur en hexadécimal et est reconvertit en binaire
 * puis le binaire donné en entrée est remplacé par la nouvelle valeur convertie en binaire */
void substitution(int bin[4]){
	int i, p=0;
	int decimal=0;
	char S;
	
	for(i=3; i>=0; i--){
		decimal = decimal + bin[i]*pow(2,p);
		p++;
	}
	
	S = boite_S[decimal];
	conversion_binaire(S, bin, 0);
	
}

/*Cette fonction prend en entrée le tableau contenant l'Etat
 * puis créée un tableau temporaire où seront placés les bits permutés à la bonne place
 * le résultat sera ensuite recopié dans le tableau Etat pour le mettre à jour */
void permutation(int Etat[taille_msg_hexa*4]){
	int i;
	int tmp[64];
	
	for(i=1; i<63; i++){
		tmp[(i*16)%63] = Etat[i];
	}
	
	for(i=1; i<63; i++){
		Etat[i] = tmp[i];
	}	
}

void cadencement_cle(int K[taille_cle_hexa*4], int* deb, int* fin, int S_cle[taille_msg_hexa*4], int tour){
	/*int i, j;
	int tmp[4];
	int tour[5];*/
	
	deb = (deb+61)%80;
	fin = (deb-1)%80;
	
	printf("deb : %p", deb);
	printf("fin : %p", fin);
	
	
}
