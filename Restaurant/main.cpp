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

	do 
	{
		cout << "\n\n-----------GESTIONNAIRE DE RESTAURANT--------------\n";
		cout << "\n 1.Generer\n 2.Quitter\n";
		cout << "---------------------------------------------------\n";
		cout << "Choissez une option: ";
		cin >> x;
		cout << "\n\n\n";
		Restaurant resto;
		switch (x)
		{
		case 1:
			resto.Creer();
			resto.Afficher();
			break;
		case 2:
			return 0;
		default:
			system("cls");
			cout << "Veuillez entrer un numero approprie\n\n";
			break;
		}
	} while (x != 2);
	
	system("Pause");
	return 0;
}