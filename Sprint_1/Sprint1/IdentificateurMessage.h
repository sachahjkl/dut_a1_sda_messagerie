#ifndef _IDMESSAGE_
#define _IDMESSAGE_

/**
* @file IdentificateurMessage.h
* Projet Sprint 1
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant de Identificateur Message
* Structures de données et algorithmes - DUT1 Paris Descartes
*/

/**
* @brief Structure de données de type IdMessage
*/
typedef char Date;
typedef char Heure;
struct IdMessage {
	enum { MAX = 21 };
	unsigned int nbBloc;
	char exp[MAX], dest[MAX];
	Date d[9];
    Heure h[9];
};

/**
* @brief Saisie de identifiant d'un message
* @return la date saisie
*/
IdMessage saisir_id(std::istream& is);

/**
* @brief Affichage de identifiant d'un message
* @param[in-out] os : le flot de sortie
* @param[in] id : l'identifiant à afficher
*/
void afficher_id(std::ostream& os, const IdMessage& id);

#endif