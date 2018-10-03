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
#include <cassert>

using namespace std;
#include "MessageEnCours.h"
void initialiser_mc(MessageEnCours& mc, const PaquetReseau& pr) {
	assert(pr.nbPR>0);
	initialiser2(mc.listeB, 1, 1); // Créer une liste vide
	mc.LgMes = 0;
    mc.nbPRecus = 0;
	mc.LastPRecu = 0;
	MessageEnCours* mec = new MessageEnCours;
}

void detruire2(MessageEnCours* mec) {
	delete mec;
	mec = NULL;
}
