#include <iostream>
#include <string>
#include "Salle.h"
#include "Groupe.h"
#include "Restaurant.h"
#include <stdlib.h> // permet de supprimer l'affichage de la console
#include "Enum.h"
using namespace std;

void SecuriserInt2(double inputVariable, string messageQuestion)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\n>> Erreur : Merci d'entrer un entier\n\n";
		cout << messageQuestion;
		cin >> inputVariable;
	}
}

int main()
{
	int x = 1;
	int exit = 2;
	static bool isGenerated = false; // verifie si le restaurant a utilisé la fonction Creer()
	int sup = 0; 
	string menu = "\n 1.Generer\n 2.Quitter\n";	// menu d'affichage présenté
	Restaurant resto;
	
	do 
	{
		cout << "\n\n-----------GESTIONNAIRE DE RESTAURANT--------------\n";
		cout << menu;
		cout << "---------------------------------------------------\n";
		cout << "Choissez une option: ";
		cin >> x;
		SecuriserInt2(x, "Merci de choisir une des options proposees: ");
		cout << "\n\n\n";
		switch (x)
		{
		case 1:
			resto.Creer();
			menu = "\n 1.Re-Generer\n 2.Afficher\n 3.Quitter\n";
			isGenerated = true;
			exit = 3;
			break;
		case 2:
			if(!isGenerated)
				return 0;
			else
			{
				resto.Afficher();
				break;
			}
		case 3:
			if(isGenerated)
			return 0;
		default:
			std::system("cls");
			cout << "Veuillez entrer un numero approprie\n\n";
			break;
		}
	} while (x != exit);
	
	std::system("Pause");
	return 0;
}