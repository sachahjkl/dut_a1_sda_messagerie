/**
* @file main.cpp
* Projet Sprint 1
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Programme pricipal
* Structures de données et algorithmes - DUT1 Paris Descartes
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include "BlocData.h"
#include "IdentificateurMessage.h"
#include "PaquetReseau.h"
using namespace std;

int main(){
	setlocale(LC_ALL, "fr-FR");
	char nomfichier[80];
	cout << "saisir le nom du fichier à lire\n";
	cin >> nomfichier;
	ifstream fligne(nomfichier, ios_base::in);
	if (fligne.fail()) {
		cerr << "Ouverture de " << nomfichier << " impossible";
		system("pause");
		exit(1);
	}
	while (fligne.good()) {
		PqReseau p = saisir_pr(fligne);
		afficher_pr(cout, p);
		cout << endl;
	}
	fligne.close();
	system("pause");
	return 0;
}
