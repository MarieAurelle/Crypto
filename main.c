/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define taille_msg_hexa 16
#define taille_cle_hexa 20
char boite_S[16] = {'b', 'f', '3', '2', 'a', 'c', '9', '1', '6', '7', '8', '0', 'e', '5', 'd', '4'};
char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};*/

#include "chiffrement.h"

/*Permet d'afficher un tableau d'int, en séparant les nombres binaires
 * de la forme : 000 0001 0010 0011 ... 1111 */
void affichage(int n, int tab[n]){
	int i;
	int espace = 1;
	for(i=0; i<n; i++){
		printf("%d", tab[i]);
		if(espace%4 == 0) printf(" ");
		espace++;
	}
}

int main(int argc, char** argv){
	
			/* Initialisation de toutes les variables nécessaires */
			
	char message_clair[taille_msg_hexa];
	//char cle_maitre[taille_cle_hexa];
	int Etat[taille_msg_hexa*4]; //puisqu'un bit en hexa vaut 4 bit en binaire
	int i;

			/* Initialisation de toutes les variables déclarées */
	
	/// Intéraction avec l'utilisateur qui entre la clé maître puis le message clair à chiffrer
	
	//printf("Entrez la cle : ");
	//scanf("%s", cle_maitre);
	printf("Entrez le message clair : ");
	scanf("%s", message_clair);
	
	/// Remplissage du registre Etat en convertissant le message_clair en binaire
	
	for(i=0; i<taille_msg_hexa*4; i=i+4){
		conversion_binaire(message_clair[i/4], Etat, i);
	}
	//affichage(taille_msg_hexa*4, Etat);
	int j=0;
	int elt[4];
	int k = 0;
	char hexa[16];
	for(i=0; i<taille_msg_hexa*4; k++){
		for(j=0; j<4; j++, i++){
			elt[j] = Etat[i];
		}
		hexa[k] = conversion_hexadecimal(elt);
	}
	
	for(i=0; i<16; i++){
		printf("%c", hexa[i]);
	}
	return 0;
}
