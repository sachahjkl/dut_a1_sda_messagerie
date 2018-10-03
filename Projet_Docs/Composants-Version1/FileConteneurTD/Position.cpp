/**
 * @file Position.cpp
 * Projet sem04-tp-Cpp3
 * @author l'équipe pédagogique 
 * @version 1 19/12/05
 * @brief Composant de positions sur une grille
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include <iostream>
#include <cassert>
using namespace std;

#include "Position.h"
/**
 * @brief Saisie d'une position valide
 * @return la position saisie
 */
Position saisir() {
	Position p;
	cout << "Position (abscisse? ordonnee?) ? "; 
	cin >> p.abscisse >> p.ordonnee;
	return p;
}
 
/**
 * @brief Affichage d'une position
 * @param[in] p : la position à afficher
 */
void afficher(const Position& p) {
	cout << "[" << p.abscisse << ", " << p.ordonnee << "] ";
}
