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
	int nbPlacesPrisesEtage;
public:
	Etage(int nbChaises = 0, int nbEtages = 0);		// Constructeur avec arguments optionnels
	void Affiche();									// Affiche les informations ainsi que le schéma d'une salle de cet étage, pour l'instant, seule la première salle est affichée
	std::string getNom();
	int getNbSalles();
	void setNbSalles(int nb);
	void SetNbPlacesPrises(int nb);
	int GetNbPlacesPrises();
	int getNbChaises();
	int getNbTables();
	int getID();
	void setID(int _id);
	void setNbChaises(int _nbChaises);
	void setNbTables(int _nbTables);
	Salle* listeSalles;								// contient l'ensemble des salles pour cet étage
	~Etage();
};


	