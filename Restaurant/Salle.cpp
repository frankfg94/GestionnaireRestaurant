#include <iostream>
#include <string>
#include "Salle.h"
#include "time.h"
#include <cstdlib>
#include "Enum.h"
#include "Restaurant.h"
#include "windows.h"
using namespace std;


Salle::Salle(int _longX = 0, int _largY = 0, int _nbChaises = 0, int _nbTables = 0)
{
	longueurX = _longX;
	LargeurY = _largY;
	nbChaises = _nbChaises; srand( (unsigned int ) time(NULL));
	nbTables = _nbTables;
	Generer();
}

Salle::Salle()
{
	longueurX = 0;
	LargeurY = 0;
	nbChaises = 0; srand((unsigned int ) time(NULL));
	nbTables = 0;
}

bool Salle::EstComplet()
{
	if (GetNbPlacesPrises() == GetNbChaises())
		return true;
	else
		return false;
}

void Salle::SetLongueurX(int l)
{
	 longueurX = l;
}

void Salle::SetLargeurY(int l)
{
	LargeurY = l;
}
	
void Salle::SetNbPlacesPrises(int nb)
{
			int total = nb + nombrePlacesPrisesSalle; // afin de pouvoir prendre en compte plusieurs groupes et pas seulement le premier si le premier est supérieur
			for (int i = 0; i < longueurX; i++)
			{
				for (int j = 0; j < LargeurY; j++)
				{
					if (nombrePlacesPrisesSalle < total)
					{
						if (tab[i][j] == '+')
						{
							tab[i][j] = 'p';
							nombrePlacesPrisesSalle++;
						}
					}
				}
			}

}

int Salle::GetNbPlacesPrises()
{
	return nombrePlacesPrisesSalle;
}

Etage* Salle::GetEtage()
{
	return etage;
}

void Salle::SetEtage(Etage* _etage)
{
	 etage = _etage;
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

int Salle::GetLargeurY()
{
	return LargeurY;
}


void Salle::AfficherInfos()
{
	cout << "//			SALLE			//\n"; // Affichage Bader
	cout << "La salle est de taille : " << longueurX << "," << LargeurY << "." << endl;
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
	tab = _schema;
}

void Salle::Modifier()
{
	cout << "Taille de la salle:" << endl;
	cout << "x: ";
	cin >> longueurX;
	cout << "y: ";
	cin >> LargeurY;
	cout << "Mobilier de la salle:" << endl;
	cout << "Nombre de chaise: ";
	cin >> nbChaises;
	cout << "Nombre de table: ";
	cin >> nbTables;
}

void Salle::ModifierierRapide(int _longX, int _largY, int _nbChaises, int _nbTables)
{
	longueurX = _longX;
	LargeurY = _largY;
	nbChaises = _nbChaises;
	nbTables = _nbChaises;
}

void Salle::Generer()
{
	// DECLARATION
	// A rajouter Y pour libérer la mémoire
	tab = new char*[LargeurY];
	for (int i = 0; i <LargeurY ; i++)
	{	
		tab[i] = new char[longueurX];
	}

	// REMPLISSAGE AVEC DES CARACTERES VIDES
	for (int y = 0; y < LargeurY ; y++)
	{
		for (int x = 0; x < longueurX; x++ ) 
		{
			tab[y][x] = ' ';
		}
	}
}
int nbP = 0;		// Nombre de places occupées pour cet affichage
void Salle::Afficher(int colors = 7) // couleur grise par défaut
{
	int x = 0;
	int y = 0;
	if(Restaurant::listeGroupes)
	cout << "\n|";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Utilisé pour modifier la couleur d'arrière plan et des caractères
	if (longueurX != 0 && LargeurY != 0)
	{
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
					if (tab[x][y] == 'p')
					{
						SetConsoleTextAttribute(hConsole, 11);	
						nbP++;
						
						if (nbP < Restaurant::listeGroupes[0].nb_pers +1 )
						{
							SetConsoleTextAttribute(hConsole, 14);
						}
						else if (Restaurant::listeGroupes[0].nb_pers + Restaurant::listeGroupes[1].nb_pers +1  > nbP)
						{
							SetConsoleTextAttribute(hConsole, 12); 
						}
						else if (Restaurant::listeGroupes[0].nb_pers + Restaurant::listeGroupes[1].nb_pers + Restaurant::listeGroupes[2].nb_pers + 6 > nbP)
						{
							SetConsoleTextAttribute(hConsole, 11);
						}
						
					}
					
					cout << tab[x][y];
					SetConsoleTextAttribute(hConsole, 7); // on remet la police d'écriture de la console en blanc

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
	else
	{
		longueurX = 10;
		LargeurY = 10;
	}
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

char** Salle::PlacerChaiseSetTables(PlacementType t)
{
	cout << endl;	
	if (t == PlacementType::compresseCouloir)
	{
		for (int x = 1; x < longueurX; x = x + 4)
		{
			for (int y = 0; y < LargeurY; y = y + 2)
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
			for (int y = 0; y < LargeurY; y = y + 2)
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
			for (int y = 0; y < LargeurY; y = y + 4)
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
			for (int y = 0; y < LargeurY; y = y + 1)
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
