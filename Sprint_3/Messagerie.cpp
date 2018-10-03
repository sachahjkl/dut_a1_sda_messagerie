/**
* @file Messagerie.cpp
* Projet Sprint 3
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

void traiterPaquetReseau(Messagerie& m, MessageEnCours& mc, PaquetReseau& pr) {
	unsigned int cpt = 0, l = longueur(m.listeM);
	if (l == 0) { // on entre directement le 1er pqrecu
		mc.IdMess = pr.IdMess;
		inserer(m.listeM, 0, mc);
	}
	for (unsigned int k = 0; k < l; k++) {
		Item a = lire(m.listeM, k);
		
		if (estEgal(pr.IdMess, a.IdMess)== true) {
			entrer(m.listeM.c.tab[k].fileB, pr.blocD);
			m.listeM.c.tab[l].nbPRecus += 1;
			m.listeM.c.tab[l].LastPRecu = pr.blocD.nbBloc;
			break;
		}
		else
			cpt = cpt + 1;
	}
	if (cpt == l && l==0) { // si pqrecu == 1er element, on n'entre que son blocdata (évite les doublons)
		entrer(m.listeM.c.tab[l].fileB, pr.blocD);
		m.listeM.c.tab[l].nbPRecus += 1;
		m.listeM.c.tab[l].LastPRecu = pr.blocD.nbBloc;
	}
	if (cpt == l && l != 0) {// si on recoit un new message
		initialiser_mc(mc); // on initialise un new MessageEnCours
		mc.IdMess = pr.IdMess;
		inserer(m.listeM, l, mc);
		entrer(m.listeM.c.tab[l].fileB, pr.blocD);
		m.listeM.c.tab[l].nbPRecus += 1;
		m.listeM.c.tab[l].LastPRecu = pr.blocD.nbBloc;
	}
	if (pr.finMess == 1) {
		m.listeM.c.tab[l].LgMes = pr.blocD.nbBloc;
	}
}

void afficher_mess(std::ostream& os, Messagerie& m) {
	unsigned int l = longueur(m.listeM);
	for (unsigned int i = 0; i < l - 1; i++) { // boucle qui parcourt la liste
		Item a = lire(m.listeM, i);
		afficher_id(os, m.listeM.c.tab[i].IdMess);
		cout << endl;
		for (unsigned int u = 0; u < m.listeM.c.tab[i].fileB.nb; u++){ // boucle qui parcourt la file
			os << m.listeM.c.tab[i].fileB.c.tab[u].data;
			if (i < l - 1) {
				cout << endl;
			}
		}
	}
}