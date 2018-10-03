#ifndef _BLOCDATA_
#define _BLOCDATA_

/**
* @file BLOCDATA.h
* Projet Sprint 1 
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

#endif
