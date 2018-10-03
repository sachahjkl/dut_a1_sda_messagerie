/**
* @file Messagerie.cpp
* Projet Sprint 2
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant de la messagerie
* Structures de données et algorithmes - DUT1 Paris Descartes
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <locale>
#include <string.h>
using namespace std;
#include "PaquetReseau.h"
#include "MessageEnCours.h"
#include "Messagerie.h"

void initialiser(Messagerie& m) {
	initialiser(m.listeM, 1, 1); //initialise une liste vide
}
void detruire(Messagerie& m) {
	detruire(m.listeM);
}

void recevoirPaquetReseau(std::istream& is, PaquetReseau& pr) {
	pr = saisir_pr(is);
}

void traiterPaquetReseau(Messagerie& m, PaquetReseau& pr) {
	unsigned int vrai = 0, l = longueur(m.listeM);
		if (l == 0) {
			inserer(m.listeM, longueur(m.listeM), pr.IdMess);
		}
		for (unsigned int k = 0; k < l; k++) {
			Item a = lire(m.listeM, k);
			if (estEgal(pr.IdMess, a) == true) {
				break;
			}
			else {
				vrai = vrai + 1;
			}
		}
		if (vrai == l && l != 0) {
			inserer(m.listeM, longueur(m.listeM), pr.IdMess);
		}
}

void afficher_mess(std::ostream& os, Messagerie& m, const PaquetReseau& pr) {
	for (unsigned int i = 0; i < longueur(m.listeM)-1; i++) {
		Item a = lire(m.listeM, i);
		cout << "m.idMes[" << i << "]=";
		afficher_id(os,a);
		cout << endl;
	}
}