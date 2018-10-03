#ifndef _MESSAGERIE_
#define _MESSAGERIE_

/**
* @file Messagerie.h
* Projet Sprint 6
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

/** 
* @brief allouer et désallouer la variable m de type Messagerie 
* @param[in] m : la messagerie à initialiser
*/
void initialiser(Messagerie& m);
void detruire(Messagerie& m);
/**
* @brief Reception d'un paquet-réseau
* @param[in-out] is : le flot d'entrée
* @param[in] pr : le Paquet réseau saisit
*/
void recevoirPaquetReseau(std::istream& is, PaquetReseau& pr);

/**
* @brief Affichage d'un message recu integralement
* @param[in-out] os : le flot de sortie
* @param[in] m : la messagerie à afficher
*/
void afficher_mess(std::ostream& os, Messagerie& m, unsigned int l);

/**
* @brief Archivage d'un message recu integralement
* @param[in-out] os : le flot de sortie
* @param[in] m : la messagerie à afficher
*/
void archiver_mess(std::ofstream& og, Messagerie& m, unsigned int l);

/**
* @brief met à jour des éléments de messagerie, le fichier log, et les mailbox
* @param[in-out] os : le flot de sortie
* @param[in] m : la messagerie à organiser
* @param[in] pr : le Paquet réseau à traiter
*/
void intermediaire(std::ostream& os, std::ofstream& log, Messagerie& m, Messagerie& suppr, PaquetReseau& pr, unsigned int i);

/**
* @brief Organiser un paquet-réseau dans la messagerie 
* @param[in-out] os : le flot de sortie
* @param[in] m : la messagerie à organiser
* @param[in] mc : le message en cours de reception
* @param[in] pr : le Paquet réseau à traiter
*/
void traiterPaquetReseau(std::ostream& os, std::ofstream& log, Messagerie& m, Messagerie& suppr, MessageEnCours& mc, PaquetReseau& pr);


#endif