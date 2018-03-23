#ifndef SALLE_H_INCLUDED
#define SALLE_H_INCLUDED

#include <iostream>
#include <string>
#include "Etage.h"

class Salle
{
private:
	int longueurX;
	int longueurY;
	int nbChaises;
	int nbTables;
	//Etage etage;

public:
	char** tab;
	Salle(int longX, int largY, int nbChaises, int nbTables);
	Salle();
	void AfficherInfos();
	void Modifier();
	void ModifierierRapide(int longueurX, int largeurY, int nbChaises, int nbTables);
	void Afficher();
	void Generer();
	void PlacerChaise(int x, int y);
	void PlacerTable(int x, int y);
	void PlacementBasique();

};

#endif // SALLE_H_INCLUDED

