/**
* @file FileAPriorite.cpp
* Projet Sprint 5
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant de file avec capacité paramétrée
* Structures de données et algorithmes - DUT1 Paris 5
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <locale>
#include <cassert>
using namespace std;
#include "BlocData.h"
#include "FileAPriorite.h"


/**
* @brief initialiser une file vide
* la file est allouée en mémoire dynamique
* @see detruire, elle est à désallouer en fin d’utilisation
* @param[out] f : la file à initialiser
* @param[in] capa : capacité de la file (nb maximum d‘items stockés)
* @pre capa>0
*/
void initialiser(FileAPriorite& f, unsigned int capa) {
	assert(capa>0);
	initialiser_TD(f.c, capa); // @see initialiser de ConteneurTD
	f.indPremier = 0;
	f.indProchain = 0;
	f.nb = 0;
}

/**
* @brief Désallouer une file
* @see initialiser, la file a déjà été allouée en mémoire dynamique
* @param[out] f : la file
*/
void detruire(FileAPriorite& f) {
	detruire_TD(f.c); // @see detruire de ConteneurTD
}

/**
* @brief Test de file pleine
* @param[in] f : la file testée
* @return true si f est pleine, false sinon
*/
bool estPleine(const FileAPriorite& f) {
	return (f.nb == f.c.capacite); // @see type ConteneurTD 
}

/**
* @brief Test de file vide
* @param[in] f : la file testée
* @return true si f est vide, false sinon
*/
bool estVide(const FileAPriorite& f) {
	return (f.nb == 0);
}

/**
* @brief Lire l'item en tête de file
* @param[in] f : la file
* @return la valeur de l'item en tête de file
* @pre la file n’est pas vide
*/
ItemF tete(const FileAPriorite& f) {
	assert(!estVide(f));
	return lire_TD(f.c, f.indPremier); // @see lire, dans ConteneurTD 
}

/**
* @brief Entrer un item dans la file
* @param[in,out] f : la file
* @param[in] it : l'item à entrer
* @pre f n’est pas pleine
*/
void entrer(FileAPriorite& f, const ItemF& it) {
	assert(!estPleine(f));
	ItemF temp;
	bool ordre;
	ecrire_TD(f.c, f.indProchain, it);
	for (unsigned int i = 0; i <= f.nb; i++) {
		ItemF a = lire_TD(f.c, i);
		for (unsigned int u = i + 1; u <= f.nb; u++) {
			ItemF b = lire_TD(f.c, u);
			ordre = enOrdre(a, b);
			if (ordre == true) {
				continue;
			}
			else if (ordre == false) {
				temp = b;
				b = a;
				a = temp;
				ecrire_TD(f.c, i, a);
				ecrire_TD(f.c, u, b);
				continue;
			}
		}
	}
	f.indProchain = (f.indProchain + 1) % f.c.capacite;
	f.nb++;
}

/**
* @brief Sortir l’item tête de file
* @param[in,out] f : la file
* @pre f n’est pas vide
*/
void sortir(FileAPriorite& f) {
	assert(!estVide(f));
	f.indPremier = (f.indPremier + 1) % f.c.capacite;;
	f.nb--;
}
