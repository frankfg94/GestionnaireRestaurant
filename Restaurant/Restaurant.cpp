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

int nbPersonnesTotal;
int Restaurant::GetNbPesonnesTotal()
{
	return nbPersonnesTotal;
}

int Restaurant::nbPersonnesTotal;
void Restaurant::SetNbPesonnesTotal(int nb)
{
	nbPersonnesTotal = nb;
}

double Restaurant::longueurResto;
double Restaurant::GetLongueurResto()
{
	return longueurResto;
}

double Restaurant::largeurResto;
double Restaurant::GetLargeurResto()
{
	return largeurResto;
}

void Restaurant::Creer()
{
	cout << "---------------MENU DE GENERATION DU RESTAURANT-----------------" << endl << endl;
	cout << " 1 / Quelle est la largeur du restaurant: "; cin >> largeurResto; SecuriserInt(largeurResto, " 1 / Quelle est la largeur du restaurant : ");
	if (largeurResto != -1)
	{
		cout << " 2 / Quelle est la longueur du restaurant: "; cin >> longueurResto; SecuriserInt(longueurResto, " 2 / Quelle est la longueur du restaurant : ");
		cout << " 3 / Combien y a t-il de groupes: "; cin >> nbGroupes; SecuriserInt(nbGroupes, " 3 / Combien y a t-il de groupes :");
		cout << " 4 / Combien y a t-il d'etages : "; cin >> nbEtages; SecuriserInt(nbEtages, " 4 / Combien y a t-il d'etages :");
		cout << endl;


		// Sécurisation des saisies négatives, par une mise en valeur absolue
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

			// Creation d'un etage et ajout à la liste
			Etage e(nbPlacesEtage[i], (int)((nbPlacesEtage[i] + 1) / 2));
			e.setID(i);
			listeEtages[i] = e;
		}

		// Création des groupes
		for (int i = 0; i < nbGroupes; i++)
		{
			Groupe g;
			g = listeGroupes[i];
			cout << "\\   Groupe " << i + 1 << "   \\" << endl;
			cout << "	a ) Entrer le nom du groupe : ";

			// cin.ignore() est necessaire pour ne pas avoir de problème d'affichage
			cin.ignore();
			getline(cin, g.nom);

			cout << "	b ) Entrer le numero de reference du groupe : "; cin >> g.nb_ref; SecuriserInt(g.nb_ref, "Numero de reference : ");
			cout << "	c ) Entrer le nombre de personnes dans le groupe : "; cin >> g.nb_pers; SecuriserInt(g.nb_pers, "Nombre de personnes : ");
			if (g.nb_pers + nbPersonnesTotal> nbPlacesTotal)
			{
				cout << "Impossible d'ajouter plus de personnes :" << g.nb_pers + nbPersonnesTotal << " invites pour " << nbPlacesTotal << " places disponibles\n\n";
			}
			nbPersonnesTotal += g.nb_pers;
			cout << endl;
			listeGroupes[i] = g;
			
		}

		// Création des étages
		for (int i = 0; i < nbEtages; i++)
		{
			// A simplifier
			Etage etage = listeEtages[i];
			for (int j = 0; j < etage.getNbSalles(); j++)
			{
				cout << "Traitement etage : " << i << endl;
				cout << "j = " << j << endl;
				if (i == 0)			etage.listeSalles[j].PlacementBasique(PlacementType::compresse);
				else if (i == 1)	etage.listeSalles[j].PlacementBasique(PlacementType::compresseCouloir);
				else if (i == 2)	etage.listeSalles[j].PlacementBasique(PlacementType::espace);
				else if (i == 3)	etage.listeSalles[j].PlacementBasique(PlacementType::fete);
				if(i == 0)
				etage.listeSalles[j].SetNbPlacesPrises(listeGroupes[0].nb_pers_groupe());
			}
		}



	}
	else
	{
		nbGroupes = 2;
		nbEtages = 4;
		largeurResto = 10;
		longueurResto = 30;
		cout << "//			Creation automatique			//\n";
		Groupe A(10, "Ten", 5173);
		Groupe B(1, "Agent special", 007);
		listeGroupes = new Groupe[nbGroupes];
		listeEtages = new Etage[nbEtages];

		for (int i = 0; i < nbEtages; i++)
		{
			listeEtages[i].setNbChaises(10 + i*10);
			int nbTables = (int)((listeEtages[i].getNbChaises() + 1) / 2);
			listeEtages[i].setNbTables(nbTables);
		}
		// On parcourt tous les étages d'indice j
		for (int i = 0; i < nbEtages; i++)
		{
			Etage etage = listeEtages[i];
			// On parcourt les salles d'indice i de cet étage d'indice j
			for (int j = 0; j < etage.getNbSalles(); j++)
			{
				cout << "Traitement etage : " << i << "	|	";
				cout << "j = " << j << endl;

				// Pour l'instant, nous avons le même nombre de chaises par étage que dans une salle car il n'y a qu'une seule salle
				etage.listeSalles[j].SetNbChaises(etage.getNbChaises());

				// On adapte le nombre de tables au nombre de chaises, en arrondissant la division à l'entier supérieur
				int nbTables = (int)((etage.getNbChaises() + 1) / 2);
				etage.listeSalles[j].SetNbTables(nbTables);

				etage.listeSalles[j].Generer();

				// On effectue un placement différent pour chaque étage
				if (i == 0)etage.listeSalles[j].PlacementBasique(PlacementType::compresse);
				else if (i == 1) etage.listeSalles[j].PlacementBasique(PlacementType::compresseCouloir);
				else if (i == 2) etage.listeSalles[j].PlacementBasique(PlacementType::espace);
				else if (i == 3) etage.listeSalles[j].PlacementBasique(PlacementType::fete);
			}
			
		}
		listeGroupes[0] = A;
		listeGroupes[1] = B;
		cout << "\nFin\n";
		return;
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
			cout << "Etage " << i << " : " << listeEtages[i].getNbChaises() << " places " << endl;
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