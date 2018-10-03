/**
 * @file testConteneurTDE_Positions.cpp
 * Projet sem04-tp-Cpp2
 * @author l'équipe pédagogique 
 * @version 2 - 26/11/11
 * @brief Test d'un conteneur de positions 
 * de type tableau à capacité extensible suivant un pas d'extension
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include <iostream>
using namespace std;

#include "ConteneurTDE.h"

/* Test d'un conteneur (de type ConteneurTDE) de positions */ 
int main() {
	ConteneurTDE cPositions; // Déclaration du conteneur de positions testé
	unsigned int nbPositions=0;// Nb de positions enregistrées dans le conteneur
	Position p;
	bool estOrigine;
	
	initialiser(cPositions, 1, 2); 
	
	/* Remplir le conteneur de positions 
	 * jusqu'à la saisie de la position origine (non enregistrée) */	
	unsigned int i = 0;
	cout << "Saisir des positions jusqu'à la saisie de l'origine (0,0)\n";
	cout << "Les positions (à l'exception de l'origine)\n";
	cout << "seront enregistrées dans le conteneur dynamique" << endl;
	do {
		p = saisir();
		estOrigine = (p.abscisse == 0) && (p.ordonnee == 0);
		if (!estOrigine) {
			ecrire(cPositions, i++, p); 
			nbPositions++;
		}
	} while (!estOrigine);
	
	/* Afficher la capacité du conteneur de positions */	
	cout << "Capacité du conteneur dynamique : " << cPositions.capacite << endl;
	
	/* Afficher le conteneur de positions */
		cout << "Conteneur alloué en mémoire dynamique de : " << nbPositions 
			 << " position(s)" << endl; 
		for (unsigned int i = 0; i < nbPositions; ++i) {
			p = lire(cPositions, i);
			afficher(p);
		}
	
	// Désallocation du conteneur
	detruire(cPositions);
	
	return 0;
}
