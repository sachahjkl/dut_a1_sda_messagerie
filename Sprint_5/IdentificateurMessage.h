#ifndef _IDMESSAGE_
#define _IDMESSAGE_

/**
* @file IdentificateurMessage.h
* Projet Sprint 5
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

/**
* @brief Compare un Idmessage recu avec les Idmessage déjà stockés en mémoire
* @param[in] id1 : le premier id à comparer
* @param[in] id2 : le second id à comparer
*/
bool estEgal(IdMessage& id1, IdMessage& id2);
#endif