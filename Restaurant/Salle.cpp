#include <iostream>
#include <string>
#include "Salle.h"
#include "time.h"
#include <cstdlib>
using namespace std;


Salle::Salle(int _longX = 0, int _largY = 0, int _nbChaises = 0, int _nbTables = 0)
{
	longueurX = _longX;
	longueurY = _largY;
	nbChaises = _nbChaises; srand( (unsigned int ) time(NULL));
	nbTables = _nbTables;
	Generer();
}

Salle::Salle()
{
	longueurX = 0;
	longueurY = 0;
	nbChaises = 0; srand((unsigned int ) time(NULL));
	nbTables = 0;
}


void Salle::AfficherInfos()
{
	cout << "//			SALLE			//\n"; // Affichage Bader
	cout << "La salle est de taille : " << longueurX << "," << longueurY << "." << endl;
	cout << "elle possede :" << nbChaises << " chaises et " << nbTables << " tables." << endl;
}

void Salle::Modifier()
{
	cout << "Taille de la salle:" << endl;
	cout << "x: ";
	cin >> longueurX;
	cout << "y: ";
	cin >> longueurY;
	cout << "Mobilier de la salle:" << endl;
	cout << "Nombre de chaise: ";
	cin >> nbChaises;
	cout << "Nombre de table: ";
	cin >> nbTables;
}

void Salle::ModifierierRapide(int _longX, int _largY, int _nbChaises, int _nbTables)
{
	longueurX = _longX;
	longueurY = _largY;
	nbChaises = _nbChaises;
	nbTables = _nbChaises;
}

void Salle::Generer()
{
	// INITIALISATION
	tab = new char*[longueurY];
	for (int i = 0; i < longueurX; i++)
	{
		tab[i] = new char[longueurX];
	}

	// REMPLISSAGE AVEC DES CARACTERES VIDES
	for (int y = 0; y < longueurY ; y++)
	{
		for (int x = 0; x < longueurX; x++ )
		{
			tab[y][x] = ' ';
			cout << tab[y][x];
		}
	}
}

void Salle::Afficher()
{
	int x = 0;
	int y = 0;
	cout << "|";
	for (int i = 0; i < longueurX; i++)
	{
		cout << "*";
	}
	cout << "|" << endl;
	for (int x = 0; x < longueurX; x++)
	{
		cout << "|";
		for (int y = 0; y < longueurX; y++)
		{
			cout << tab[x][y];
		}
		cout << "|" << endl;
	}
	cout << "|";
	for (int j = 0; j < longueurX; j++)
	{
		cout << "*";
	}
	cout << "|" << endl;
	cout << "Il y a " << nbChaises << " chaises en reserve et " << nbTables << " tables en reserve" << endl;
}

void Salle::PlacerChaise(int x, int y)
{
	tab[y][x] = '+';
}

void Salle::PlacerTable(int x, int y)
{
	tab[y][x] = '#';
}

void Salle::PlacementBasique()
{
	int x = 0;
	for (int w = 0; w < longueurX; w = w + 2)
	{
		for (int i = 1; i + 1 < longueurY; i = i + 4)
		{
			if (nbTables > 0 && nbChaises > 0)
			{
					tab[i - 1][w] = '+';
					nbChaises--;
				tab[i][w] = '#';
				if (nbChaises > 0)
				{
					tab[i + 1][w] = '+';
					nbChaises--;
				}
				nbTables--;
			}
		}
	}
}
