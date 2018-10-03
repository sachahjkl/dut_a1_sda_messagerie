#ifndef _MESSAGE_EN_COURS_
#define _MESSAGE_EN_COURS_


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
#include "Liste.h"
struct  Messagerie{
	enum { MAX = 21 };
	Liste listeM;
};

/** allouer et désallouer la variable m de type Messagerie */
void initialiser(Messagerie& m);
void detruire(Messagerie& m);

/** @brief Reception d'un paquet-réseau */
void recevoirPaquetReseau(std::istream& is, PaquetReseau& pr);

/** @brief Organiser un paquet-réseau dans la messagerie */
void traiterPaquetReseau(Messagerie& m, const PaquetReseau& pr);

#endif