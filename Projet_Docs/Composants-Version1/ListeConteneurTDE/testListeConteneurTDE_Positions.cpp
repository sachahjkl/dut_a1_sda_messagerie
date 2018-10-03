/**
 * @file testListeConteneurTDE_Positions.cpp
 * Projet sem06-tp-Cpp3
 * @author l'équipe pédagogique 
 * @version 2 - 13/01/10
 * @brief Test d'une liste de positions dont le conteneur 
 * est un tableau à capacité extensible suivant un pas d'extension
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include <iostream>
using namespace std;
 
#include "Liste.h"

/* Test d'une liste de positions */ 
int main(int argc, char* argv[]) {

	Liste lPositions; 	// Déclaration de la liste de positions
	Position p;
	
	initialiser(lPositions, 1, 1);	// Créer une liste de vide
	
	cout << "Test d'une liste de positions" << endl;
	
	/* Ajout de positions en début de liste
	 * jusqu'à la saisie d'une position d'absisse 0 (non ajoutée) */	
	cout << "Saisir des positions jusqu'à la saisie de l'origine [0,0]\n";  
	cout << "Les positions (à l'exception de celle de l'origine)\n";
	cout << "seront ajoutées en début de liste" << endl;
	bool estOrigine;
	do {
		p = saisir();
		estOrigine = (p.abscisse == 0) && (p.ordonnee == 0);
		if (!estOrigine) inserer(lPositions, 0, p); 
	} while (!estOrigine);
	
	/* afficher tous les éléments de la liste */
	for (unsigned int i = 0; i < longueur(lPositions); ++i) 
		afficher(lire(lPositions, i));
	cout << endl;
	
	cout << "Insertion de l'élément [7,8] en fin de liste\n";
	p.abscisse = 7; p.ordonnee = 8;
	inserer(lPositions, longueur(lPositions), p);
	cout << "Insertion de l'élément [8,7] en fin de liste\n";
	p.abscisse = 8; p.ordonnee = 7;
	inserer(lPositions, longueur(lPositions), p);
	
	/* suppression du deuxième élément de liste */
	cout << "Suppression du deuxième élément de liste\n";
	supprimer(lPositions, 1);
	
	cout << "Longueur de la liste :" << longueur(lPositions) << endl;
	
	cout << "Affichage de la liste :\n";
	for (unsigned int i = 0;i < longueur(lPositions);i++) 
		afficher(lire(lPositions, i));
	cout << endl;
	
	/* destruction de la liste */
	detruire(lPositions);
	
	return 0;
}
