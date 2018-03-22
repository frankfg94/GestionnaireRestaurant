#include <iostream>
#include <string>
#include "Salle.h"
#include "Groupe.h"
#include "Mobilier.h"
#include "Restaurant.h"
#include <stdlib.h> // permet de supprimer l'affichage de la console
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

ostream &operator<<(ostream &os, const Groupe &g)
{
	return os << "(nom:" << g.nom << "; nb:" << g.nb_pers << "; ref:" << g.nb_ref << ")\n";

}

int main()
{
	/* Main Yoann 
	Salle sal;
	sal.aff_info_salle();
	sal.modif_salle();
	sal.aff_info_salle();
	sal.aff_salle();
	*/
	
	Groupe A(0, "Dupont", 212);
	cout << A << "OK";

	int x = 1;
	int exit = 2;
	static bool isGenerated = false; // verifie si le restaurant a utilisé la fonction Creer()
	int sup = 0; 
	string menu = "\n 1.Generer\n 2.Quitter\n";
	Restaurant resto;
	Salle s;
	s.Generer(10, 10);
	s.Afficher(10, 10);
	cout << "stop" << endl;
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
			cout << "Placer les tables ?\n";
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
			system("cls");
			cout << "Veuillez entrer un numero approprie\n\n";
			break;
		}
	} while (x != exit);
	
	system("Pause");
	return 0;
}