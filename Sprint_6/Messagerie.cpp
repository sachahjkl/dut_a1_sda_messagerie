/**
* @file Messagerie.cpp
* Projet Sprint 6
* @author Abelhaj Youssef et Froment Sacha G106
* @version 1 - 14/12/2017
* @brief Composant de la messagerie
* Structures de données et algorithmes - DUT1 Paris Descartes
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <locale>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)
#include "PaquetReseau.h"
#include "MessageEnCours.h"
#include "Messagerie.h"

void initialiser(Messagerie& m) {
	initialiser(m.listeM, 1, 1); //initialise une liste vide
}
void detruire(Messagerie& m) {
	detruire(m.listeM);
}

void recevoirPaquetReseau(std::istream& is, PaquetReseau& pr) {
	pr = saisir_pr(is);
}

void afficher_mess(std::ostream& os, Messagerie& m, unsigned int l) {
	afficher_id(os, m.listeM.c.tab[l].IdMess);
	os << endl;
	for (unsigned int u = 0; u < m.listeM.c.tab[l].fileB.nb; u++) { 
		os << m.listeM.c.tab[l].fileB.c.tab[u].data;
	}
	os << endl << endl;
}
void archiver_mess(std::ofstream& og, Messagerie& m, unsigned int l) {
	afficher_id(og, m.listeM.c.tab[l].IdMess);
	og << endl;
	for (unsigned int u = 0; u < m.listeM.c.tab[l].fileB.nb; u++) { 
		og << m.listeM.c.tab[l].fileB.c.tab[u].data;
	}
	og << endl;
}

void intermediaire(std::ostream& os, std::ofstream& log, Messagerie& m, Messagerie& suppr, PaquetReseau& pr, unsigned int i) {
	m.listeM.c.tab[i].nbPRecus += 1;
	m.listeM.c.tab[i].LastPRecu = pr.nbPR;
	if (pr.finMess == 1) {  // si une fin de message est détéctée
		m.listeM.c.tab[i].LgMes = pr.blocD.nbBloc; // mise à jour de sa longueur
		log << pr.nbPR << " Detection de fin de message ";
		afficher_id(log, pr.IdMess);
		log << " " << pr.finMess << " " << pr.blocD.nbBloc << endl;
	}
	if (m.listeM.c.tab[i].nbPRecus == m.listeM.c.tab[i].LgMes) { // si un message est recu integralement...
		afficher_mess(os, m, i);  // ...on l'affiche
		/* les opérations suivantes servent à créer des mail-box
		en prenant compte du nom de chaque destinataire */
		char *s1 = "mailbox";
		/* on recupère le nom du destinataire 
		sans la première lettre (ex : r1a4, r5a8, ll, ... )*/
		char *s2 = m.listeM.c.tab[i].IdMess.dest + 1; 
		char *s3 = ".txt";
		/* maj [80] : chaine de caractère qui contiendra la majuscule 
		qui se trouve au debut du nom du destinataire (ex : G, A...)*/
		char maj[80]; 
		// maj2 : chaine de charactère qui contiendra le nom complet du destinataire
		char *maj2 = NULL; 
		// s4 : chaine de caractère qui contiendra le nom complet de la mailbox
		char *s4 = NULL; 
		// on copie la première lettre du nom du destinataire dans maj	
		strncpy(maj, m.listeM.c.tab[i].IdMess.dest, 1); 
		maj[1] = '\0';
		int v = 0;
		//Opération visant à transformer le contenu de maj en majuscule
		for (v = 0; maj[v] != '\0'; v++)
		{
			// si la lettre contenue dans la chaine de caractère maj est une minuscule
			if (maj[v] >= 'a' &&  maj[v] <= 'z')
				/* alors en utilisant les positions des caractère dans la table ASCII
				on transforme le contenu de maj en majuscule*/
				maj[v] -= 'a' - 'A';
		}
		// on concatène les chaines de caractère composant le nom du destinataire
		maj2 = (char *)malloc((strlen(maj) + strlen(s2)) * sizeof(char));
		strcpy(maj2, maj);
		strcat(maj2, s2);
		// on concatène les chaines de caractère composant le nom de la mailbox
		s4 = (char *)malloc((strlen(s1) + strlen(maj2) + strlen(s3)) * sizeof(char));
		strcpy(s4, s1);
		strcat(s4, maj2);
		strcat(s4, s3);
		// on initialise un flot d'entré et un flot de sortie sur la mailbox
		ofstream mailbox(s4, ios_base::out | ios::app);
		ifstream mailbox2(s4, ios_base::out | ios::app);
		/*opération servant à afficher le titre d'une mailbox
		sans doublons (ex : Mailbox all)*/
		char titre[80];
		mailbox2 >> titre; // on lit le titre de la mailbox
		if (strcmp(titre, "Mailbox") != 0) { // si la mailbox n'a pas de titre...
			// ...alors on y ajoute un titre 
			mailbox << "Mailbox " << pr.IdMess.dest << endl;
		}
		archiver_mess(mailbox, m, i); // archivage du message dans sa mailbox
		log << pr.nbPR << " Archivage mailbox "; // et mise à jour du fichier log
		log << pr.IdMess.dest << " " << pr.IdMess.d << " " << pr.IdMess.h << endl;
	}
	for (unsigned int k = 0; k < m.listeM.nb; k++) {
		Item a = lire(m.listeM, k);
		if (pr.nbPR >= a.LastPRecu + 10) {
			inserer(suppr.listeM, longueur(suppr.listeM), a);
			supprimer(m.listeM, k);
			log << pr.nbPR << " Perte de paquet, suppression de message ";
			afficher_id(log, a.IdMess);
			log << endl;
		}
	}
}

void traiterPaquetReseau(std::ostream& os, std::ofstream& log, Messagerie& m, Messagerie& suppr, MessageEnCours& mc, PaquetReseau& pr) {
	unsigned int cpt = 0, l = longueur(m.listeM);
	for (unsigned int k = 0; k < l; k++) {
		Item a = lire(m.listeM, k);
		if (estEgal(pr.IdMess, a.IdMess)== true) {
			entrer(m.listeM.c.tab[k].fileB, pr.blocD);
			/*fonction qui met à jour le fichier log, les mailbox, et supprime
			les messages perdus*/
			intermediaire(os, log, m, suppr, pr, k);
			break;
		}
		else
			cpt = cpt + 1;
	}
	if (cpt == l) {
		log << pr.nbPR << " Detection de nouveau message ";
		afficher_id(log, pr.IdMess);
		log << " " << pr.finMess << " " << pr.blocD.nbBloc << endl;
		initialiser_mc(mc); // on initialise un nouveau MessageEnCours
		mc.IdMess = pr.IdMess;
		inserer(m.listeM, l, mc);
		entrer(m.listeM.c.tab[l].fileB, pr.blocD);
		/*fonction qui met à jour le fichier log, les mailbox, et supprime
		les messages perdus*/
		intermediaire(os, log, m, suppr, pr, l);
	}
}