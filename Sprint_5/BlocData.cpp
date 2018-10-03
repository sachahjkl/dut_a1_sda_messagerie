/**
* @file BlocData.cpp
* Projet Sprint 5
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant de bloc de donnée
* Structures de données et algorithmes - DUT1 Paris Descartes
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "BlocData.h" 
BlocData saisir_bd(istream& is) {
	BlocData b;
	is >> b.nbBloc;
	nettoyerLigne(is);
	is.getline(b.data, BlocData::MAX);
	return b;
}
void afficher_bd(ostream& os, const BlocData& b) {
	os << b.nbBloc << endl;
	os << b.data << " ";
}

void nettoyerLigne(std::istream& is) {
	is.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
}

bool enOrdre(const BlocData& b1, const BlocData& b2) {
	if (b1.nbBloc < b2.nbBloc) {
		return true;
	}
	else
		return false;
}