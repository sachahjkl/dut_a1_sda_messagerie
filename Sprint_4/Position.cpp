/**
 * @file Position.cpp
 * Projet Sprint 4
 * @author Abelhaj Youssef et Froment Sacha G106
 * @version 1 - 14/12/2017
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

bool enOrdre(const Position& p1, const Position& p2) {
	if (p1.abscisse < p2.abscisse) {
		return true;
	}
	else
		return false;
}
