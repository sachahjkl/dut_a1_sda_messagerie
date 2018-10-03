#ifndef _MESSAGERIE_
#define _MESSAGERIE_

/**
* @file Messagerie.h
* Projet Sprint 2
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant de la messagerie
* Structures de données et algorithmes - DUT1 Paris Descartes
*/

#include "PaquetReseau.h"
#include "Liste.h"

/**
* @brief Structure de données de type Messagerie
*/

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
void traiterPaquetReseau(Messagerie& m, PaquetReseau& pr);

/** @brief Affichage d'un paquet-réseau */
void afficher_mess(std::ostream& os, Messagerie& m, const PaquetReseau& pr);

#endif