#include <iostream>
#include <string>
#include "Salle.h"

using namespace std;


Salle::Salle()
{
    coord_x = 0;
    coord_y = 0;
    nb_chaise = 0;
    nb_table = 0;
}

void Salle::aff_info_salle()
{
    cout << "La salle est de taille : "<< coord_x << "," << coord_y << "." << endl;
    cout << "elle possede :"<< nb_chaise << " chaises et " << nb_table << " tables." << endl;
}

void Salle::modif_salle()
{
    cout << "Taille de la salle:" << endl;
    cout << "x: ";
    cin >> coord_x;
    cout << "y: ";
    cin >> coord_y;
    cout << "Mobilier de la salle:" << endl;
    cout << "Nombre de chaise: ";
    cin >> nb_chaise;
    cout << "Nombre de table: ";
    cin >> nb_table;
}

void Salle::modif_salle_fast(int longueurX, int largeurY, int nbChaises, int nbTables)
{
	coord_x = longueurX;
	coord_y = largeurY;
	nb_chaise = nbChaises;
	nb_table = nbChaises;
}

void Salle::test_salle()
{
	cout << "1" << endl;
	tab = new char*[coord_y];
}



char** Salle::Generer(int sizeX, int sizeY)
{
	tab = new char*[sizeX];
	for (int i = 0; i < sizeX; ++i)
		tab[i] = new char[sizeY];
	for (int x = 0; x <sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			tab[x][y] = '*';
		}
	}
	return tab;
}

void Salle::Afficher(int zoneX, int zoneY)
{
	for (int x = 0; x < zoneX; x++)
	{
		for (int y = 0; y < zoneY; y++)
		{
			cout << tab[x][y];
		}
		cout << "\n";
	}
}
