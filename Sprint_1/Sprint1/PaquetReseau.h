#ifndef _PAQUETRESEAU_
#define _PAQUETRESEAU_


/**
* @file PaquetReseau.h
* Projet Sprint 1
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant du paquet réseau
* Structures de données et algorithmes - DUT1 Paris Descartes
*/

/**
* @brief Structure de données de type PqReseau
*/
#include "BlocData.h" 
#include "IdentificateurMessage.h"
struct PqReseau {
	enum { MAX = 21 };
	unsigned int nbPR;
	IdMessage IdMess;
	BlocData blocD;
	bool finMess;
};

/**
* @brief Saisie d'un Paquet réseau
* @return le Paquet réseau saisit
*/
PqReseau saisir_pr(std::istream& pr);

/**
* @brief Affichage d'un Paquet réseau
* @param[in-out] os : le flot de sortie
* @param[in] pr : le Paquet réseau à afficher
*/
void afficher_pr(std::ostream& os, const PqReseau& pr);

#endif