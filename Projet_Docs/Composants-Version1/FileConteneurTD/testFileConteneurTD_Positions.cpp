/**
 * @file testFilePositions.cpp
 * Projet sem06-cours-Cpp1
 * @author l'équipe pédagogique 
 * @version 1 - 25/01/06
 * @brief Test d'une file de positions dont le conteneur est
 * un tableau circulaire à capacité fixée en mémoire dynamique
 * Structures de données et algorithmes - DUT1 Paris 5
 */
 
#include <iostream>
using namespace std;
 
#include "File.h"

/* Test d'une file (en mémoire dynamique et à capacité paramétrée
 * d'éléments de type Position */ 
int main() {

	File fPositions; // Déclaration de la file de positions
	Position p;
	
	/* Initialisation de la file de capacité 5 */ 
	initialiser(fPositions, 5);
	
	cout << "Test de la file de positions" << endl;
	
	/* Test de file vide */ 
	cout << "Début de l'application : ";
	if (estVide(fPositions)) cout << "la file est vide" << endl;
	else cout << "la file n'est pas vide" << endl;
	
	/* Ajout de positions dans la file jusqu'à la saisie 
	 * d'une date d'année nulle (date non empilée) */	
	cout << "Saisir des positions jusqu'à la saisie de l'origine [0,0]\n";  
	cout << "Les positions (à l'exception de celle de l'origine)\n";
	cout << "seront ajoutées à la file de capacité " 
		 << fPositions.c.capacite << endl;
	bool estOrigine;
	unsigned short nbSaisies =0;
	do {
		p = saisir();
		estOrigine = (p.abscisse == 0) && (p.ordonnee == 0);
		if (!estOrigine) { 
			nbSaisies++; 
			entrer(fPositions, p); 
		}
	} while (!estOrigine);
	
	cout << "Etat de la file après " << nbSaisies << " position(s) entrée(s) :";
	if (estVide(fPositions)) cout << " la file est vide" << endl;
	else cout << " la file n'est pas vide" << endl;
	
    // Sortie de file d'un elément si la file n'est pas vide
    cout << "Sortie de file d'un élément si la file n'est pas vide" << endl;
	if (!estVide(fPositions)) sortir(fPositions);
    
    // Entrée de file d'un nouvel élément [7, 8] si la file n'est pas pleine
    cout << "Entrée de file d'un nouvel élément [7, 8] " 
             "si la file n'est pas pleine" << endl;
    p.abscisse = 7; p.ordonnee = 8;
 	if (!estPleine(fPositions)) entrer(fPositions, p);
		
	/* Afficher l'état de la file (par défilage complet)  */
	cout << "Défilage complet de la file : " << endl;
	while (!estVide(fPositions)) {
		cout << "Elément sorti de file : ";
		/* Afficher la tête de file */
		afficher(tete(fPositions)); cout << endl;
		/* Sortir l'élément en tête de file */
		sortir(fPositions);
	}
	cout << "Fin de défilage, la file est vide";
	
	detruire(fPositions);
	
	return 0;
}
