#include <iostream>
#include "Groupe.h"
#include "Etage.h"
class Restaurant
{
private:
	static double largeurResto;
	static double longueurResto;
	static int nbPersonnesTotal;
	static int nbPersonnesPlacees;
    int* nbPlaceSetage;								// tableau indiquant le nombre de places pour chaque etage
	int nbPlacesTotal;								//nombre total de places
	static int nbGroupes;							//nombre de groupes
	std::string typeResto;							// type de restaurant
public:
	static int GetNbGroupes();						//le nombre de groupes rentré
	static int GetNbPersonnesPlacees();				//le nombre de personnes placées
	static void SetNbPersonnesPlacees(int nb);		//choix du nombre de personnes placées
	std::string GetTypeResto();						// obtient le type de resto
	std::string SetTypeResto();						//choix du type de resto
	int GetNbPlacesTotal();							//nombre total de places 
	static int GetNbPesonnesTotal();				//nombre de personnes total
	static void SetNbPesonnesTotal(int nb);			//choix du nombre de personnes total
	static double GetLongueurResto();				//dimension du resto X
	static double GetLargeurResto();				//dimension du resto Y
	void EnregistrerGroupes(int nbGroupes);			//enregistre le nombre de groupes
	void SecuriserNeg();							// Sécurisation des saisies négatives, par une mise en valeur absolue
    int nbEtages;
	static Groupe* listeGroupes;					// contient l'ensemble des groupes
	Etage * listeEtages;							// contient l'ensemble des etages
	void SaisirTypeRestaurant();					//choix du type de resto, utilisation du polymorphisme			
	void Creer();									// lance la création du resto (mise en place des tables + étages + salles)
	Restaurant(double _largeur = 0, double _longueur = 0, int _etages = 0, int * _places = 0);	// Constructeur avec paramètres optionnels
	void Afficher();								//affiche le resto étage par étage avec ses salles
};
