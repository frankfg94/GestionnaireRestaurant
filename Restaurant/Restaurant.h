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
    int* nbPlaceSetage; // tableau indiquant le n	ombre de places pour chaque etage
	int nbPlacesTotal;
	static int nbGroupes;
	Mobilier mobilier;
	char* tabchar;
	std::string typeResto;
public:
	static int GetNbGroupes();
	std::string GetTypeResto();
	std::string SetTypeResto();
	int GetNbPlacesTotal();
	static int GetNbPesonnesTotal();
	static void SetNbPesonnesTotal(int nb);
	static double GetLongueurResto();
	static double GetLargeurResto();
	void EnregistrerGroupes(int nbGroupes);
	void SecuriserNeg();								// Sécurisation des saisies négatives, par une mise en valeur absolue
    int nbEtages;
	static Groupe* listeGroupes;// contient l'ensemble des groupes
	Etage * listeEtages;
	void SaisirTypeRestaurant();
	// contient l'ensemble des etages
	void Creer(); // retourne un tableau dynamique des données essentielles
	Restaurant(double _largeur = 0, double _longueur = 0, int _etages = 0, int * _places = 0);
	void Afficher();
};