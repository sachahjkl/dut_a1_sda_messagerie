#ifndef _BLOCDATA_
#define _BLOCDATA_

/**
* @file BLOCDATA.h
* Projet Sprint 5
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant de BlocData
* Structures de données et algorithmes - DUT1 Paris Descartes
*/

/**
* @brief Structure de données de type BlocData
*/
struct BlocData {
	enum { MAX = 21 };
	unsigned int nbBloc;
	char data[MAX];
};

/**
* @brief Saisie d'un bloc de données
* @return le bloc saisit
*/
BlocData saisir_bd(std::istream& is);

/**
* @brief Affichage d'un bloc de données
* @param[in-out] os : le flot de sortie
* @param[in] b : le bloc de données à afficher
*/
void afficher_bd(std::ostream& os,const BlocData& b);

/**
* @brief ignore les whites spaces
* @param[in-out] is : le flot d'entrée
*/
void nettoyerLigne(std::istream& is);

/**
* @brief relation d'ordre entre 2 positions
* @param[in] b1 : le 1er bloc de données
* @param[in] b2 : le 2ème bloc de données
* @return true si b1 et b2 sont ordonnés, false sinon
*/
bool enOrdre(const BlocData& b1, const BlocData& b2);

#endif
