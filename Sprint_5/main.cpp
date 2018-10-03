/**
* @file main.cpp
* Projet Sprint 5
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Programme pricipal
* Structures de données et algorithmes - DUT1 Paris Descartes
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <locale>

using namespace std;
#include "MessageEnCours.h"
#include "Messagerie.h"
int main(){
	setlocale(LC_ALL, "fr-FR");


	Messagerie m;	
	PaquetReseau pr;
	MessageEnCours mc;

	char nomfichier[80];	
	cout << "saisir le nom du fichier à lire\n";
	cin >> nomfichier;
	ifstream fligne(nomfichier, ios_base::in);

	if (fligne.fail()) {
		cerr << "Ouverture de " << nomfichier << " impossible";
		system("pause");
		exit(1);
	}
	initialiser(m);
	initialiser_mc(mc);
	unsigned int a = 0;
	while (fligne.good()) {
		recevoirPaquetReseau(fligne, pr);
		traiterPaquetReseau(m, mc, pr);
	}
	afficher_mess(cout, m);
	detruire_mc(mc);
	detruire(m);
	fligne.close();
	system("pause");
	return 0;
}
