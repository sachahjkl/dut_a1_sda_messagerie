/**
* @file MessageEncours.cpp
* Projet Sprint 3
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant de message en cours
* Structures de données et algorithmes - DUT1 Paris Descartes
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>

using namespace std;
#include "MessageEnCours.h"
void initialiser_mc(MessageEnCours& mc) {
	initialiser(mc.fileB, 255);
	mc.LgMes = 0;
    mc.nbPRecus = 0;
	mc.LastPRecu = 0;
}

void detruire_mc(MessageEnCours& mc) {
	detruire(mc.fileB);
}
