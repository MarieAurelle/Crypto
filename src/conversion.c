#include "conversion.h"

					//* CE FICHIER CONTIENT LES FONCTIONS DE CONVERSIONS *//

/*Cette fonction prend en entrée le chiffre hexa qu'elle doit convertir en binaire
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

/* Cette fonction prend en entrée l'entier décimal à convertir en binaire
 * et le tableau où stocker le résultat puis renvoie le tableau
 * remplit en binaire correspondant à l'entier entré */
void conversion_decimal(int entier, int bin[5]){
	int i = 4, j;
	
			/// Initialisation du tableau avec des 0 ///
	for(j=0; j<5; j++){ 
		bin[j] = 0;
	}

			/// Remplissage du tableau par la fin en binaire ///
	while(entier != 0){
		bin[i] = entier%2;
		entier = entier/2;
		i--;
	}
}
