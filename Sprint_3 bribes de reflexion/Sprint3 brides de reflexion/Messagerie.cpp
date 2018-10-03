/**
* @file PaquetReseau.cpp
* Projet Sprint 1
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant du paquet réseau
* Structures de données et algorithmes - DUT1 Paris Descartes
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "PaquetReseau.h"
#include "MessageEnCours.h"
#include "Messagerie.h"

void initialiser(Messagerie& m) {
	Messagerie* mgr = new Messagerie;
}
void detruire(Messagerie* mgr) {
	delete mgr;
	mgr = NULL;
}

void recevoirPaquetReseau(std::istream& is, PaquetReseau& pr) {
	saisir_pr(is);
}

void traiterPaquetReseau(Messagerie& m, const PaquetReseau& pr) {
	MessageEnCours mc;
	ecrire(m.listeM, longueur(m.listeM), mc);
}