# Cryptographie

- DESCRIPTION DU PROJET :

Le but de ce projet est de pouvoir entrer un message clair en notation hexadecimale et d'en ressortir un message chiffré. Pour cela le code est
découpé en 4 parties :

	- La première est appelée conversion.c et prend en charge toutes les fonctions de conversion d'hexadecimal en binaire (conversion_binaire)
	  et de décimal en binaire (conversion_decimal). Le fichier conversion.h contient quant à lui, en plus des fonctions présentes dans le fichiers
	  .c toutes les bibliothèques nécessaires au code ainsi que les defines.
	  
	- La seconde est appelée affichage.c et prend en charge toutes les fonctions d'affichage, soit en binaire directement, soit en hexadecimal. 
	  Elle contient également le tableau hexa en varibale globale afin de pouvoir convertir un binaire en hexadecimal.
	  Le fichier .h associé inclus conversion.h afin de donner accès aux bibliothèques et aux defines.
	  
	- La troisième partie appelée chiffrement.c prend en charge toutes les fonctions nécessaires au chiffrement du message ainsi qu'au mélange
	  de la clé maitre, c'est à dire XOR, substitution_msg (la fonction "substitution" est utilisée dans le cadencement de clé également),
	  permutation et cadencement_clé. Elle contient également le tableau boite-S en variables globale afin de pouvoir connaitre la substitution
	  à effectuer dans la fonction substitution. Le fichier .h associé inclus affichage.h afin de donner accès aux bibliothèques et aux defines.
	  
	- La quatrième et dernière partie contient le main et inclus chiffrement.h pour avoir accès à toutes les fonctions ainsi que toutes les
	  bibliothèques et les defines.

- COMPILATION ET EXECUTION DU PROJET :

Pour compiler le code, il suffit d'aller à la racine du projet, donc dans le dossier "Aurelle_Marie_Projet_Crypto", où se trouve le Makefile.
Il faut utiliser la commande "make" pour compiler, les fichiers .c et .h nécessaires vont aller être chercher dans le dossier src et les fichiers
.o générés vont être placés dans le dossier obj. Une fois l'édition de lien effectuée, l'exécutable appelé "programme" va être placé dans le
dossier bin. Il suffit alors d'ouvrir le dossier bin (cd bin) puis de taper la commande "./programme". 

A ce moment le programme va se lanceret vous demander la clé maitre à entrer, vous aller donc devoir entrer une clé en hexadecimal de 20 bits. 
Ensuite, le message clair va vous êtredemandé et il faudra entrer un message clair en hexadecimal de 16 bits.Le programme va vous générer 
directement le message chiffré correspondant.
