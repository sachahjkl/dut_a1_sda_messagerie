#ifndef _MESSAGE_EN_COURS_
#define _MESSAGE_EN_COURS_


/**
* @file MessageEnCours.h
* Projet Sprint 5
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant  de message en cours
* Structures de données et algorithmes - DUT1 Paris Descartes
*/

/**
* @brief Structure de données de type MessageEnCours
*/
#include "PaquetReseau.h"
#include "FileAPriorite.h"
struct  MessageEnCours{
	enum { MAX = 21 };
	IdMessage IdMess;
	FileAPriorite fileB;
	unsigned int LgMes;
	unsigned int nbPRecus;
	unsigned int LastPRecu;
};

/** Initialiser et allouer en mémoire dynamique
la variable m de type MessageEnCours */
void initialiser_mc(MessageEnCours& mc);


/** Désallouer la variable m de type MessageEnCours */
void detruire_mc(MessageEnCours& mc);

#endif