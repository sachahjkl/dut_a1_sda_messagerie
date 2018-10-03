/**
* @file main.cpp
* Projet Sprint 6
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
	Messagerie suppr;
	PaquetReseau pr;
	MessageEnCours mc;

	char nomfichier[80];
	cout << "saisir le nom du fichier à lire\n";
	cin >> nomfichier;
	ifstream fligne(nomfichier, ios_base::in);
	ofstream log("log.txt", ios_base::out|ios::trunc);
	if (fligne.fail()) {
		cerr << "Ouverture de " << nomfichier << " impossible";
		system("pause");
		exit(1);
	}
	initialiser(m);
	initialiser(suppr);
	while (fligne.good()) {
		recevoirPaquetReseau(fligne, pr);
		traiterPaquetReseau(cout, log, m, suppr, mc, pr);
	}
	log << "Fin de transmission";
	for (unsigned int i = 0; i < longueur(suppr.listeM); i++) {
		log << ", suppression de message ";
		afficher_id(log, suppr.listeM.c.tab[i].IdMess);
	}
	detruire_mc(mc);
	detruire(m);
	detruire(suppr);
	fligne.close();
	log.close();
	system("pause");
	return 0;
}
