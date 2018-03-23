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
public:
	Etage();
	void Affiche();
	std::string getNom();
	std::string getSchema();
	int getNbChaises();
	int getNbTables();
	int getID();
	void setID(int _id);
	void setNbChaises(int _nbChaises);
	void setNbTables(int _nbTables);
	~Etage();
};