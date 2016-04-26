#include "chiffrement.h"

					//* CE FICHIER CONTIENT LES FONCTIONS UTILES POUR LE CHIFFREMENT *//

/* Cette fonction prend en entrée un tableau contenant le nombre binaire à modifier
 * calcule sa valeur décimale pour aller chercher sa nouvelle valeur dans le tableau boite_S
 * trouve sa nouvelle valeur en hexadécimal et est reconvertie en binaire
 * puis le binaire donné en entrée est remplacé par la nouvelle valeur convertie en binaire */
void substitution(int bin[4]){
	
			/// Déclarations des variables ///
	int i, p, decimal;
	char S;
	
			/// Initialisation des variables ///
	p = 0;
	decimal = 0;
	
			/// Valeur en décimale ///
	for(i=3; i>=0; i--){
		decimal = decimal + bin[i]*pow(2,p);
		p++;
	}
	
			/// Recherche de la valeur dans le tableau boite_S ///
	S = boite_S[decimal];
	
			/// Conversion de l'hexa en binaire ///
	conversion_binaire(S, bin, 0);
}

/* Cette fonction permet de substituer le message en entier */
void substitution_msg(int Etat[taille_msg_hexa*4]){
	
			/// Déclarations des variables ///
	int i,j;
	int* tmp;

			/// Initialisation des variables ///
	tmp = malloc(sizeof(int)*4);
	
			/// Substitution ///
	for(i=0; i<taille_msg_hexa*4; 1){ //Sur toute la longueur du message...
			for(j=0; j<4; i++, j++){ //...on remplit tmp 4 par 4...
				tmp[j] = Etat[i];
			}
			substitution(tmp); //...on fait la substitution...
			for(j=0, i=i-4; j<4; i++, j++){ //...on le remet à la bonne place dans le message.
				Etat[i] = tmp[j];
			}
		}
	free(tmp);	
}

/* Cette fonction prend en entrée le tableau contenant l'Etat
 * puis créée un tableau temporaire où seront placés les bits permutés à la bonne place
 * le résultat sera ensuite recopié dans le tableau Etat pour le mettre à jour */
void permutation(int Etat[taille_msg_hexa*4]){
	
			/// Déclaration et initialisation des varaibles ///
	int i, j, indice;
	int traite[taille_msg_hexa*4] = {0}; //tableau bien remplit par des 0
	int tmp[2] = {0,0};
	
			/// Permutation ///
	for(i=1; i<taille_msg_hexa*4 -1; i++){
		if(traite[i] == 0){ // On vérifie que la valeur que l'on veut déplacer n'a pas déjà été deplacée auparavant...
			traite[i] = 1;
			tmp[1] = Etat[i]; //...puis on la stocke dans tmp[1]...
			indice = i; //...on initialise notre indice...
			
			for(j=0; j<3; j++){ //...puis sur trois tours on va permuter les valeurs...
				indice = indice*taille_msg_hexa%(taille_msg_hexa*4 -1); //...en prenant l'indice de la case où doit aller notre valeur dans tmp[1]...
				tmp[0] = Etat[indice]; //...puis on stocke la valeur de la case qui va être modifiée dans tmp[0]...
				Etat[indice] = tmp[1]; //...ici on échange les valeurs...
				tmp[1] = tmp[0]; //...on ramène la valeur sauvegardée dans tmp[0] dans tmp[1] pour aller la placer ailleurs...
				traite[indice] = 1; //...et on dit qu'on a traité l'indice en question.
			}
		} 
	}				
}

/* Cette fonction fait le cadencement de clé en prenant en entrée le registre
 * contenant la clé maitre puis l'indice de début du tableau par rapport aux 
 * permutations effectuées sur la clé et le numéro du tour courant */
void cadencement_cle(int K[taille_cle_hexa*4], int* deb, int tour){
	
			/// Déclaration des variables ///
	int i, j;
	int* tmp;
	int* tours;
	
			/// Initialisation des variables ///
	tmp = malloc(sizeof(int)*4);
	tours = malloc(sizeof(int)*5);
	conversion_decimal(tour, tours);
	
			/// Calcul du nouveau début du tableau (permutation des 61 positions vers la gauche ///
	*deb = (*deb+61)%80;
	
			///On fait la substitution des 4 bits les plus à gauche du registre ///
	for(i=*deb, j=0; j<4; i = (i+1)%80, j++){ // En partant de deb jusqu'à deb+4...
		tmp[j] = K[i];						// ...on stocke les valeurs dans tmp...
	}
	substitution(tmp); //...on les substitue...
	for(i=*deb, j=0; j<4; i = (i+1)%80, j++){//...et on les replace au même endroit d'où on les a prise.
		K[i] = tmp[j];
	}
	
			/// XOR avec le numéro du tour courant ///
	for(i=(*deb+60)%80, j=0; j<5; i = (i+1)%80, j++){ // On prend les 5 bits k19-k15 et on les XOR avec le numéro du tour convertit en binaire...
		K[i] = XOR(tours[j], K[i]); 				 // ...et on le remplace directement dans le registre de la clé.
	}
	free(tours);
}

/* Cette fonction permet de faire l'opération XOR entre 2 entiers */
int XOR(int a, int b){
	if(a == b) return 0;
	else return 1;
}
