#ifndef _POSITION_
#define _POSITION_

/**
 * @file Position.h
 * Projet Sprint 4
 * @author Abelhaj Youssef et Froment Sacha G106
 * @version 1 - 14/12/2017
 * @brief Composant de positions sur une grille
 * Structures de données et algorithmes - DUT1 Paris 5
 */
 
/**
 * @brief Type position
 * invariant : la position doit être valide
*/
struct Position {
	unsigned int abscisse; // abscisse de la position
	unsigned int ordonnee; // ordonnée de la position
};

/**
 * @brief Saisie d'une position valide
 * @return la position saisie
 */
 Position saisir();
 
/**
 * @brief Affichage d'une position
 * @param[in] p : la position à afficher
 */
void afficher(const Position& p);

/**
* @brief relation d'ordre entre 2 positions
* @param[in] p1 : la 1ère position
* @param[in] p2 : la 2ème position
* @return true si p1 et p2 sont ordonnés, false sinon
*/
bool enOrdre(const Position& p1, const Position& p2);
#endif

