#include <iostream>
#include "Groupe.h"
#include "Etage.h"
#include "Mobilier.h"
class Restaurant
{
private:
	static double largeurResto;
	static double longueurResto;
	static int nbPersonnesTotal;
    int* nbPlacesEtage; // tableau indiquant le n	ombre de places pour chaque etage
	int nbPlacesTotal;
	int nbGroupes;
	Mobilier mobilier;
	Groupe* listeGroupes;// contient l'ensemble des groupes
	char* tabchar;
public:
	int GetNbGroupes();
	int GetNbPlacesTotal();
	static int GetNbPesonnesTotal();
	static void SetNbPesonnesTotal(int nb);
	static double GetLongueurResto();
	static double GetLargeurResto();
    int nbEtages;
	Etage * listeEtages; // contient l'ensemble des etages
	void Creer(); // retourne un tableau dynamique des données essentielles
	Restaurant(double _largeur = 0, double _longueur = 0, int _etages = 0, int * _places = 0);
	void Afficher();
};