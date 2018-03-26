#include <iostream>
#include <string>
#include "Salle.h"
#include "time.h"
#include <cstdlib>
#include "Enum.h"
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

void Salle::SetLongueurX(int l)
{
	 longueurX = l;
}

void Salle::SetLongueurY(int l)
{
	longueurY = l;
}

int Salle::GetLongueurX()
{
	return longueurX;
}

int Salle::GetNbChaises()
{
	return nbChaises;
}

void Salle::SetNbChaises(int _nbChaises)
{
	nbChaises = _nbChaises;
}

void Salle::SetNbTables(int _nbTables)
{
	nbTables = _nbTables;
}

int Salle::GetNbTables()
{
	return nbTables;
}

int Salle::GetLongueurY()
{
	return longueurY;
}


void Salle::AfficherInfos()
{
	cout << "//			SALLE			//\n"; // Affichage Bader
	cout << "La salle est de taille : " << longueurX << "," << longueurY << "." << endl;
	cout << "elle possede :" << nbChaises << " chaises et " << nbTables << " tables." << endl;
}

char** Salle::GetSchema()
{
	return tab;
}

std::string Salle::ConvertChar2DToString(char ** tab, int sizeX, int sizeY)
{
	string schema = "";
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			schema += tab[x][y];
		}
		schema += '\n';
	}
	return schema;
}

void Salle::SetSchema(char** _schema)
{
	schema = _schema;
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
			//cout << tab[y][x];
		}
	}
}

void Salle::Afficher()
{
	int x = 0;
	int y = 0;
	cout << "\n|";
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
	if (nbChaises > 0)
	{
		tab[y][x] = '+';
		nbChaises--;
	}

}

void Salle::PlacerTable(int x, int y)
{
	if (nbTables > 0)
	{
		tab[y][x] = '#';
		nbTables--;
	}

}

//void Salle::PlacementBasique()
//{
//	int x = 0;
//	int espacementLongueur = 4;
//	int espacementHauteur = 2;
//	for (int w = 0; w < longueurX; w = w + espacementHauteur)
//	{
//
//		for (int i = 1; i + 1 < longueurY; i = i + espacementLongueur)
//		{
//			if (i % 2 == 0) espacementLongueur = 7; 
//			else espacementLongueur = 4;
//				// i pos en hauteur
//				// w pos en longueur
//				// premiere chaise
//					PlacerChaise(i-1,w);
//
//				// Table
//
//					PlacerTable(i, w);	
//
//				// deuxieme chaise
//					PlacerChaise(i + 1, w);
//		}
//	}
//}


char** Salle::PlacementBasique(PlacementType t)
{
	cout << "Placement lance" << endl;
	if (t == PlacementType::compresseCouloir)
	{
		for (int x = 1; x < longueurX; x = x + 4)
		{
			for (int y = 0; y < longueurY; y = y + 2)
			{
				if (y % 4 != 0)
				{
					PlacerChaise(x - 1, y);
					PlacerTable(x, y);
					PlacerChaise(x + 1, y);
				}
				else
				{
					PlacerChaise(x - 1, y + 1);
					PlacerTable(x, y + 1);
					PlacerChaise(x + 1, y + 1);
				}
			}
		}
		return tab;
	}
	else if (t == PlacementType::compresse)
	{
		for (int x = 1; x < longueurX; x = x + 4)
		{
			for (int y = 0; y < longueurY; y = y + 2)
			{
				PlacerChaise(x - 1, y);
				PlacerTable(x, y);
				PlacerChaise(x + 1, y);
			}
		}
		return tab;
	}
	else if (t == PlacementType::espace)
	{
		for (int x = 1; x < longueurX; x = x + 6)
		{
			for (int y = 0; y < longueurY; y = y + 4)
			{
				PlacerChaise(x - 1, y);
				PlacerTable(x, y);
				PlacerChaise(x + 1, y);
			}
		}
		return tab;
	}
	else if (t == PlacementType::fete)
	{
		for (int x = 1; x < longueurX; x = x + 4)
		{
			for (int y = 0; y < longueurY; y = y + 1)
			{
				PlacerChaise(x - 1, y);
				PlacerTable(x, y);
				PlacerChaise(x + 1, y);
			}
		}
		return tab;
	}
	else
	{
		cout << "Placement auto";
	}
	return tab;
}
