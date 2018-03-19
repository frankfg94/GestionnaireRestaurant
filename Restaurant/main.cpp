#include <iostream>
#include <string>
#include "Salle.h"
#include "Groupe.h"
#include "Mobilier.h"
#include "Restaurant.h"
#include <stdlib.h> // permet de supprimer l'affichage de la console
using namespace std;

int main()
{
	/* Main Yoann 
	Salle sal;
	sal.aff_info_salle();
	sal.modif_salle();
	sal.aff_info_salle();
	sal.aff_salle();
	*/
	
	/* Main Denis
	Groupe A(0, "Dupont", 212);
	cout << "Nom de reservation : " << A.nom << endl;
	cout << "Nombre de personne : " << A.nb_pers_groupe() << endl;
	cout << "Numero de reference de reservation : " << A.nb_ref_groupe() << endl;
	*/
	int x = 1;
	int exit = 2;
	static bool isGenerated = false;
	int sup = 0;
	string menu = "\n 1.Generer\n 2.Quitter\n";
	Restaurant resto;
	do 
	{
		cout << "\n\n-----------GESTIONNAIRE DE RESTAURANT--------------\n";
		cout << menu;
		cout << "---------------------------------------------------\n";
		cout << "Choissez une option: ";
		cin >> x;
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
			system("cls");
			cout << "Veuillez entrer un numero approprie\n\n";
			break;
		}
	} while (x != exit);
	
	system("Pause");
	return 0;
}