#pragma once

#include "Salle.h"
#include <iostream>
#include <string>



// A implementer à la fin : Salle* listeSalles
class Etage
{
private:
	std::string nom;
	std::string schema;
    int id;
	int nbChaises;
	int nbTables;
	int nbSalles;
	int nbPlacesPriseSetage;
public:
	Etage(int nbChaises = 0, int nbEtages = 0);		// Constructeur avec arguments optionnels
	void Affiche();														// Affiche les informations ainsi que le schéma d'une salle de cet étage, pour l'instant, seule la première salle est affichée
	std::string GetNom();
	int GetNbSalles();
	bool ResteDesPersonnesAPlacer();
	void RepartirChaiseSetTablesDansChaqueSalle();
	void RemplirSallesAvecPlacesEntrees(int nbPersonnesTotal);
	void SetNbSalles(int nb);
	int GetNbPlacesPrises();
	int GetNbChaises();
	int GetNbTables();
	int GetID();
	void SetID(int _id);
	void SetNbChaises(int _nbChaises);
	void SetNbTables(int _nbTables);
	Salle* listeSalles;													// contient l'ensemble des salles pour cet étage
	~Etage();
};


	