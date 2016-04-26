#include "affichage.h"

					//* CE FICHIER CONTIENT LES FONCTIONS D'AFFICHAGE *//

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

/* Cette fonction convertie puis affiche en hexa une clé/un message
 * dont n correspond à la taille en hexa, cad soit 16, soit 20 */
void affichage_en_hexa(int n, int binaire[n*4], char hexadecimal[n]){
	
			/// Déclaration des variables ///
	int i, j, p, k, l;
	int decimal;
	int* tmp;
	
			/// Initialisations des variables ///
	p = 0;
	decimal = 0;
	tmp = malloc(sizeof(int)*4);
	
			/// Remplissage du tableau de caractère ///
	for(i=0, k=0; i<n*4 && k<n; k++){ //sur l'ensemble du message/de la clé...
		decimal = 0;
		p = 0;
		for(j=0; j<4; j++, i++){ //...on remplit tmp 4 par 4...
			tmp[j] = binaire[i];
		}
		for(l=3; l>=0; l--){ //...on transforme le binaire en décimal et on va chercher l'hexa correspondant dans le rableau hexa...
			decimal = decimal + tmp[l]*pow(2,p);
			p++;
		}
		hexadecimal[k] = hexa[decimal]; //...puis on le stocke dans le tableau de char...
	}
	
			/// Affichage ///
	for(i=0; i<16; i++){ //...et on affiche caractère par caractère le tableau obtenu.
		printf("%c", hexadecimal[i]);
	}
	free(tmp);
}
