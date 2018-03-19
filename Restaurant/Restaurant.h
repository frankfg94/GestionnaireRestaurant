#include <iostream>
#include "Groupe.h"
#include "Etage.h"
class Restaurant
{
private:
	double largeurResto;
	double longueurResto;
	int nbEtages;
	int nbPersonnesTotal;
	int* nbPlacesEtage; // tableau indiquant le nombre de places pour chaque etage
	int nbPlacesTotal;
	int nbGroupes;
	Groupe* listeGroupes;// contient l'ensemble des groupes
	Etage* listeEtages;
public:
	void Creer(); // retourne un tableau dynamique des données essentielles
	Restaurant(double _largeur = 0, double _longueur = 0, int _etages = 0, int * _places = 0);
	void Afficher();
};