/**
* @file BlocData.cpp
* Projet sem04-cours-Cpp1
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 29/11/2014
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
	is >> ws;
	is.getline(b.data, BlocData::MAX);
	is >> ws;
	return b;
}
void afficher_bd(ostream& os, const BlocData& b) {
	os << b.nbBloc << endl;
	os << b.data << " ";
}
