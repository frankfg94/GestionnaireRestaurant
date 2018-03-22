#include "Mobilier.h"
#include <iostream>

Mobilier::Mobilier(int _etage, int _nbChaises = 0, int _nbTables = 0)
{
	etage = _etage;
	nbChaises = _nbChaises;
	nbTables = _nbTables;
}

void Mobilier::ModifierMobilier( int _nbChaises = 0, int _nbTables = 0)
{
	nbTables = _nbTables;
	nbChaises = _nbChaises;
}

void Mobilier::AfficherMobilierTotal()
{

}

void Mobilier::AfficherStats()
{
	std::cout << "Nombre de chaise"  <<this->GetNbChaises() << std::endl;
	std::cout << "Nombre de tables"<< this->GetNbTables() << std::endl;
	std::cout << "Pour l'étage n'°" << this->GetNumEtage() << std::endl;
}

int Mobilier::GetNbTables()
{
	return nbTables;
}

int Mobilier::GetNbChaises()	
{
	return nbChaises;
}

int Mobilier::GetNumEtage()
{
	return etage;
}

int Mobilier::AjouterTables(int _NbChaises)
{
	nbChaises = nbChaises + _NbChaises;
	return nbTables;
}

int Mobilier::AjouterChaises(int _NbTables)
{
	nbChaises = nbChaises + _NbTables;
	return nbChaises;
}
