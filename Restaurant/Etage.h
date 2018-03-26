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
public:
	Etage();
	void Affiche();
	std::string getNom();
	int getNbSalles();
	void setNbSalles(int nb);
	int getNbChaises();
	int getNbTables();
	int getID();
	void setID(int _id);
	void setNbChaises(int _nbChaises);
	void setNbTables(int _nbTables);
	Salle* listeSalles; // contient l'ensemble des salles
	~Etage();
};


	