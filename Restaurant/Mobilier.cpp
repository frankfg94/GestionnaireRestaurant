#include "Mobilier.h"
#include <iostream>

Mobilier::Mobilier(int _etage, int _NbChaises = 0, int _NbTables = 0)
{
	etage = _etage;
	nbChaises = _NbChaises;
	nbTables = _NbTables;
}

void Mobilier::ModifierMobilier( int _NbChaises = 0, int _NbTables = 0)
{
	nbTables = _NbTables;
	nbChaises = _NbChaises;
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
