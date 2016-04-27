#include "chiffrement.h"

					//* CE FICHIER CONTIENT LE FONCTION MAIN *//

int main(int argc, char** argv){
	
			/// Déclaration des variables ///
	char message_clair[taille_msg_hexa];
	char cle_maitre[taille_cle_hexa];
	char msg_chiffre[taille_msg_hexa];
	int Etat[taille_msg_hexa*4]; //puisqu'un bit en hexa vaut 4 bit en binaire
	int K[taille_cle_hexa*4];
	int S_cle[taille_msg_hexa*4];
	int i, deb = 0, j, k;
	
			/// Intéraction avec l'utilisateur qui entre la clé maître puis le message clair à chiffrer ///
	printf("Entrez la cle : ");
	scanf("%s", cle_maitre);
	printf("Entrez le message clair : ");
	scanf("%s", message_clair);
	
			/// Remplissage du registre Etat en convertissant le message_clair en binaire ///
	for(i=0; i<taille_msg_hexa*4; i=i+4){
		conversion_binaire(message_clair[i/4], Etat, i);
	}
	
			/// Remplissage du registre K en convertissant la cle_maitre en binaire ///
	for(i=0; i<taille_cle_hexa*4; i=i+4){
		conversion_binaire(cle_maitre[i/4], K, i);
	}
	
			/// Début du chiffrement ///
	for(i=1; i<31; i++){
		
		// Extraction de la sous clé //
		for(j = deb, k=0; k<taille_msg_hexa*4;k++, j = (j+1)%(taille_cle_hexa*4)){
			S_cle[k] = K[j];
		}
		
		// XOR avec la sous-cle //
		for(j=0; j<taille_msg_hexa*4; j++){
			Etat[j] = XOR(Etat[j], S_cle[j]);
		}
		
		// Substitution de Etat //
		substitution_msg(Etat);
		
		// Permutation de Etat //
		permutation(Etat);
		
		// Cle maitre mélangée //
		cadencement_cle(K, &deb, i);
	}
	
	/// Extraction de la dernière sous clé ///
		for(j = deb, k=0; k<taille_msg_hexa*4;k++, j = (j+1)%(taille_cle_hexa*4)){
			S_cle[k] = K[j];
		}

	/// XOR avec la dernière sous-cle ///
		for(j=0; j<taille_msg_hexa*4; j++){
			Etat[j] = XOR(Etat[j], S_cle[j]);
		}
	
	printf("Message chiffre : ");
	affichage_en_hexa(taille_msg_hexa, Etat, msg_chiffre);
	return 0;
}
