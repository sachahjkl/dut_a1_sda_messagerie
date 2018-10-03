/**
* @file PaquetReseau.cpp
* Projet Sprint 3
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
PaquetReseau saisir_pr(istream& is) {
	PaquetReseau pr;
	is >> pr.nbPR;
	pr.IdMess = saisir_id(is);
	is >> pr.finMess;
	pr.blocD = saisir_bd(is);
	return pr;
}
void afficher_pr(ostream& os, const PaquetReseau& pr) {
	os << pr.nbPR << " ";
	afficher_id(os, pr.IdMess);
	os << pr.finMess << " ";
	afficher_bd(os, pr.blocD);
}
