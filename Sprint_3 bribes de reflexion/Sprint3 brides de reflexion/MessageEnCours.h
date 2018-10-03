#ifndef _MESSAGERIE_
#define _MESSAGERIE_


/**
* @file MessageEnCours.h
* Projet Sprint 1
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant du paquet réseau
* Structures de données et algorithmes - DUT1 Paris Descartes
*/

/**
* @brief Structure de données de type PqReseau
*/
#include "PaquetReseau.h"
#include "Liste2.h"
struct  MessageEnCours{
	enum { MAX = 21 };
	IdMessage IdMess;
	Liste2 listeB;
	unsigned int LgMes;
	unsigned int nbPRecus;
	unsigned int LastPRecu;
};

/** Initialiser et allouer en mémoire dynamique
la variable m de type MessageEnCours */
void initialiser_mc(MessageEnCours& mc, const PaquetReseau& pr);

/** Désallouer la variable m de type MessageEnCours */
void detruire_mc(MessageEnCours& mc);

#endif