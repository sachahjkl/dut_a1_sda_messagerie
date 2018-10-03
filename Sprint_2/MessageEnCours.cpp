/**
* @file MessageEncours.cpp
* Projet Sprint 2
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
void initialiser_mc(MessageEnCours& mc, const PaquetReseau& pr) {
	assert(pr.nbPR>0);
	mc.LgMes = 0;
    mc.nbPRecus = 0;
	mc.LastPRecu = 0;
}

/*FONCTION "DETRUIRE" INUTILE POUR L'INSTANT*/

/*void detruire_mc(MessageEnCours& mc) {

}*/
