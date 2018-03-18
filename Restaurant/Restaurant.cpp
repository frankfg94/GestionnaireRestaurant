#include "restaurant.h"
#include <string>
#include <iostream>
using namespace std;

void Restaurant::Creer()
{
	int* data = new int[20];
	cout << "---------------MENU DE GENERATION DU RESTAURANT-----------------" << endl << endl;
	cout << " 1 / Quelle est la largeur du restaurant: ";cin >> largeurResto;
	cout << " 2 / Quelle est la longueur du restaurant: ";cin >> longueurResto;
	cout << " 3 / Combien y a t-il de groupes: ";cin >> nbGroupes;
	cout << " 4 / Combien y a t-il d'etages: ";cin >> nbEtages;
	cout << endl;

	// Initialisation dynamique
	nbPlacesEtage = new int[nbEtages];
	listeGroupes = new Groupe[nbGroupes];

	for (int i = 0; i < nbGroupes; i++)
	{
		Groupe g;
		g = listeGroupes[i];
		cout << "\\   Groupe " << i+1 << "   \\" << endl;
		cout << "	a ) Entrer le nom du groupe : "; 

		cin.ignore();
		getline(cin, g.nom); // cin.ignore() est necessaire pour ne pas sauter de lignes


		cout << "	b ) Entrer le numero de reference du groupe : "; cin >> g.nb_ref ;
		cout << "	c ) Entrer le nombre de personnes dans le groupe : "; cin >> g.nb_pers;
		cout << endl;
	}
	cout << "\\   Etages   \\" << endl;
	for (int i = 0; i < nbEtages; i++)
	{
		cout << "	Combien y a t-il de places a l'etage " << i << ": ";
		cin >> nbPlacesEtage[i];
	}
}

Restaurant::Restaurant(double _largeur, double _longueur, int _etages, int*	_places)
	{
	// Initialisation plus rapide sans "assistance"
		largeurResto = _largeur;
		longueurResto = _longueur;		
		nbEtages = _etages;
		nbPlacesEtage = _places;
	}

	void Restaurant::Afficher()
{
		cout << "\n\n-------------Informations sur le restaurant-------------\n\n";
		cout << "Votre restaurant a une largeur de " << largeurResto << "m, une longueur de " << longueurResto << "m\n et a " << nbEtages << "etages." << endl;
		for(int i = 0; i < nbEtages; i++)
		{
			cout << "Etage "<< i<<" : " << nbPlacesEtage[i] << " places " << endl;
		}
}