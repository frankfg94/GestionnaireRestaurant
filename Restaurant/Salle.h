#pragma once
#include <iostream>
#include <string>
#include "Enum.h"
class Salle
{
private:
	int longueurX;
	int longueurY;
	int nbChaises;
	int nbTables;
	char** schema;
	//Etage etage;

public:
	char** tab;
	Salle(int longX, int largY, int nbChaises, int nbTables);
	Salle();
	void SetLongueurX(int l);
	void SetLongueurY(int l);
	int GetLongueurX();
	int GetNbChaises();
	void SetNbChaises(int _nbChaises);
	void SetNbTables(int _nbTables);
	int GetNbTables();
	int GetLongueurY();
	void AfficherInfos();
	char** GetSchema();
	static std::string ConvertChar2DToString(char ** tab, int sizeX, int sizeY);
	void SetSchema(char** schema);
	void Modifier();
	void ModifierierRapide(int longueurX, int largeurY, int nbChaises, int nbTables);
	void Afficher();
	void Generer();
	void PlacerChaise(int x, int y);
	void PlacerTable(int x, int y);
	char** PlacementBasique(PlacementType t);
};
