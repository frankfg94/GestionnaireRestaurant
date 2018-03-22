#pragma once
#include <string>
#include "ObjetMobilier.h"
class Mobilier
{
public :
	Mobilier(int _NumEtage, int _NbChaises, int _NbTables);
	void ModifierMobilier(int _NbChaises, int _NbTables);
	void AfficherMobilierTotal(); // exception, seule fois où ce n'est pas pour tout l'étage
	void AfficherStats();
	int GetNbTables();
	int GetNbChaises();
	int GetNumEtage();
	int AjouterTables(int _NbChaises);
	int AjouterChaises(int _NbTables);

private: 
	int nbTables = 0;
	int nbChaises = 0;
	int etage;
	ObjetMobilier* equipement;
};

