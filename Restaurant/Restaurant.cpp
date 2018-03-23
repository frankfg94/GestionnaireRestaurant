#include "restaurant.h"
#include <string>
#include <iostream>
#include <cmath>


using namespace std;

void SecuriserInt(double inputVariable, string messageQuestion)
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



int Restaurant::GetNbGroupes()
{
	return nbGroupes;
}

int Restaurant::GetNbPlacesTotal()
{
	return nbPlacesTotal;
}

int Restaurant::GetNbPesonnesTotal()
{
	return nbPersonnesTotal;
}

double Restaurant::GetLongueurResto()
{
	return longueurResto;
}

double Restaurant::GetLargeurResto()
{
	return largeurResto;
}

void Restaurant::Creer()
{
	int* data = new int[20];
	cout << "---------------MENU DE GENERATION DU RESTAURANT-----------------" << endl << endl;
	cout << " 1 / Quelle est la largeur du restaurant: "; cin >> largeurResto; SecuriserInt(largeurResto, " 1 / Quelle est la largeur du restaurant : ");
	cout << " 2 / Quelle est la longueur du restaurant: ";cin >> longueurResto; SecuriserInt(longueurResto, " 2 / Quelle est la longueur du restaurant : ");
	cout << " 3 / Combien y a t-il de groupes: ";cin >> nbGroupes; SecuriserInt(nbGroupes, " 3 / Combien y a t-il de groupes :");
	cout << " 4 / Combien y a t-il d'etages : ";cin >> nbEtages; SecuriserInt(nbEtages, " 4 / Combien y a t-il d'etages :");
	cout << endl;

	nbGroupes = abs(nbGroupes);
	nbEtages = abs(nbEtages);
	largeurResto = abs(largeurResto);
	longueurResto = abs(largeurResto);

	// Initialisation dynamique
	nbPlacesEtage = new int[nbEtages];
	listeGroupes = new Groupe[nbGroupes];
	listeEtages = new Etage[nbEtages];

	cout << "\\   Etages   \\" << endl;
	for (int i = 0; i < nbEtages; i++)
	{
		cout << "	Combien y a t-il de places a l'etage " << i << ": ";
		cin >> nbPlacesEtage[i];
		nbPlacesTotal += nbPlacesEtage[i];

		// On met à jour l'étage correspondant
		listeEtages[i].setID(i);
		listeEtages[i].setNbChaises(nbPlacesEtage[i]);
		
	}

	for (int i = 0; i < nbEtages; i++)
	{
		listeEtages[i].Affiche();
	}

	for (int i = 0; i < nbGroupes; i++)
	{
		Groupe g;
		g = listeGroupes[i];
			cout << "\\   Groupe " << i + 1 << "   \\" << endl;
			cout << "	a ) Entrer le nom du groupe : ";

			cin.ignore();
			getline(cin, g.nom); // cin.ignore() est necessaire pour ne pas sauter de lignes

		cout << "	b ) Entrer le numero de reference du groupe : "; cin >> g.nb_ref ;
		cout << "	c ) Entrer le nombre de personnes dans le groupe : "; cin >> g.nb_pers;
		if(g.nb_pers + nbPersonnesTotal> nbPlacesTotal)
		{
			cout << "Impossible d'ajouter plus de personnes :" << g.nb_pers + nbPersonnesTotal << " invites pour " << nbPlacesTotal << " places disponibles\n\n";
			
			cout << "Re-entrer le numero de reference du groupe : "; cin >> g.nb_pers;
		}
		nbPersonnesTotal += g.nb_pers;
		cout << endl;
	}

	if (nbPlacesTotal < nbPersonnesTotal)
	{
		cout << "\n(!) Le nombre d'invites est superieur au nombre de places disponible\n" << nbPersonnesTotal<<" invites pour "<< nbPlacesTotal <<" places disponibles\n\n";
	}
}

Restaurant::Restaurant(double _largeur, double _longueur, int _etages, int*	_places)
	{
	// Initialisation plus rapide sans "assistance"
		largeurResto = _largeur;
		longueurResto = _longueur;		
		nbEtages = _etages;
		nbPlacesEtage = _places;
	}



// Utilisation des flèches directionnelles

#define KEY_UP 72

#define KEY_DOWN 80

#define ESC 27

#include <conio.h>


	void Restaurant::Afficher()
{
		cout << "\n\n-------------Informations sur le restaurant-------------\n\n";
		cout << "Votre restaurant a une largeur de " << largeurResto << "m, une longueur de " << longueurResto << "m\n et a " << nbEtages << "etages." << endl;

		for (int i = 0; i < nbGroupes; i++)
		{
			cout << "Groupe " << listeGroupes[i].nom << " : " << listeGroupes[i].nb_pers << " personnes ("<< listeGroupes[i].nb_ref <<")" << endl;
		}

		for (int i = 0; i < nbEtages; i++)
		{
			cout << "Etage " << i << " : " << nbPlacesEtage[i] << " places " << endl;
		}

		int c = 0;
		int i = 0;
		do
		{
			system("cls");
			cout << "\n//		Etage		"<< i+1 <<  "/"<< nbEtages <<"		//\n";
			if (i == 0) cout << " \n\n>>			 Etage Initial!\n\n";
			else if (i >= nbEtages - 1) cout << "\n\n>>			 Etage Final!\n\n";
			listeEtages[i].Affiche();
			switch ((c = _getch()))
			{
			case KEY_UP:
			{
				if (i < nbEtages -1)
				{
					i++;
				}
				break;
			}

			case KEY_DOWN:
			{
				if ( i > 0 )
				{
					i--;
				}
				break;
			}
			default:
			{
				break;
			}
			}
			c = 0; // on annule la valeur enregistree pour pouvoir en entrer une nouvelle
		} while (c != ESC);
		cout << "Touche ESC pressee, sortie de notre affichage etage par etage\n";

}