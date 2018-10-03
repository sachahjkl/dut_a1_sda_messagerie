/**
* @file IdentificateurMessage.cpp
* Projet Sprint 1
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant de Identificateur Message
* Structures de données et algorithmes - DUT1 Paris Descartes
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "IdentificateurMessage.h" 
IdMessage saisir_id(istream& is) {
	IdMessage id;
	is >> id.exp; 
	is >> id.dest;
	is >> id.d;
	is >> id.h;
	return id;
}
void afficher_id(ostream& os, const IdMessage& id) {
	os << id.exp << " ";
	os << id.dest << " ";
	os << id.d << " ";
	os << id.h << " ";
}
