/**
* @file main.cpp
* Projet Sprint 2
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

	PaquetReseau pr;
	MessageEnCours mc;
	Messagerie m;

	char nomfichier[80];
	initialiser_mc(mc, pr);
	initialiser(m);
	
	cout << "saisir le nom du fichier à lire\n";
	cin >> nomfichier;
	ifstream fligne(nomfichier, ios_base::in);

	if (fligne.fail()) {
		cerr << "Ouverture de " << nomfichier << " impossible";
		system("pause");
		exit(1);
	}
	while (fligne.good()) {
			recevoirPaquetReseau(fligne, pr);
			traiterPaquetReseau(m, pr);
	}
	// fonction afficher crée par moi pour vérifier que ce qu'il ya dans la liste
	// correspond bien au JDT demandé
	afficher_mess(cout, m, pr);
	detruire(m);
	fligne.close();
	system("pause");
	return 0;
}
