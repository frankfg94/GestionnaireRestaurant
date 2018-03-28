#include "restaurant.h"
#include <string>
#include <iostream>
#include <cmath>			// utilisé ici pour les valeurs absolues
#include <windows.h>		// utilisé pour changer la couleur des caractères
#include "Groupe.h"
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

Groupe* Restaurant::listeGroupes;
int Restaurant::nbGroupes;
int Restaurant::GetNbGroupes()
{
	return nbGroupes;
}

std::string Restaurant::GetTypeResto()
{
	return typeResto;
}

std::string Restaurant::SetTypeResto()
{
	return typeResto;
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

void Restaurant::EnregistrerGroupes(int nbGroupes)
{
	// INITIALISATION
	listeGroupes = new Groupe[nbGroupes];
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
		Restaurant::SetNbPesonnesTotal( GetNbPesonnesTotal() + g.nb_pers);
		cout << endl;
		listeGroupes[i] = g;

	}
}

void Restaurant::SecuriserNeg()
{
	nbGroupes = abs(nbGroupes);
	nbEtages = abs(nbEtages);
	largeurResto = abs(largeurResto);
	longueurResto = abs(largeurResto);
}

#include <iostream>
#include "botest.h"
#include <stdlib.h>

using namespace std;

void Restaurant::SaisirTypeRestaurant()
{
	string type;
	Francais Fr;
	Indien In;
	Japonnais Jp;
	Italien It;
	Chinois Ch;
	FastFood Ff;
	Pizzeria Pi;
	Kebab Ke;
	Creperie Cr;
	BarTapas Bt;
	int test = 0;

	Categorie *afffr = &Fr;
	Categorie *affIn = &In;
	Categorie *affJp = &Jp;
	Categorie *affIt = &It;
	Categorie *affCh = &Ch;
	Categorie *affFf = &Ff;
	Categorie *affPi = &Pi;
	Categorie *affKe = &Ke;
	Categorie *affCr = &Cr;
	Categorie *affBt = &Bt;

	cout << "Choississez le type de votre restaurant:" << endl << endl;
	cout << "1 = Francais        6  = Fast-Food" << endl << "2 = Indien          7  = Pizzeria" << endl << "3 = Japonnais       8  = Kebab" << endl << "4 = Italien         9  = Creperie" << endl << "5 = chinois         10 = Bar a tapas" << endl << endl;
	cin >> test;
	if (test == 0 || test >= 11)
	{
		cout << "mauvaise saisie" << endl;
		return;
	}
	else if (test == 1)
	{
		type = afffr->aff_categorie();
	}
	else if (test == 2)
	{
		type = affIn->aff_categorie();
	}
	else if (test == 3)
	{
		type = affJp->aff_categorie();
	}
	else if (test == 4)
	{
		type = affIt->aff_categorie();
	}
	else if (test == 5)
	{
		type = affCh->aff_categorie();
	}
	else if (test == 6)
	{
		type = affFf->aff_categorie();
	}
	else if (test == 7)
	{
		type = affPi->aff_categorie();
	}
	else if (test == 8)
	{
		type = affKe->aff_categorie();
	}
	else if (test == 9)
	{
		type = affCr->aff_categorie();
	}
	else if (test == 10)
	{
		type = affBt->aff_categorie();
	}
	cout << "Type enregistre : " + type << endl;

}


void Restaurant::Creer()
{
	cout << "---------------MENU DE GENERATION DU RESTAURANT-----------------" << endl << endl;
	SaisirTypeRestaurant();
	cout << " 1 / Quelle est la largeur du restaurant: "; cin >> largeurResto; SecuriserInt(largeurResto, " 1 / Quelle est la largeur du restaurant : ");
	if (largeurResto != -1)
	{
		cout << " 2 / Quelle est la longueur du restaurant: "; cin >> longueurResto; SecuriserInt(longueurResto, " 2 / Quelle est la longueur du restaurant : ");
		cout << " 3 / Combien y a t-il de groupes: "; cin >> nbGroupes; SecuriserInt(nbGroupes, " 3 / Combien y a t-il de groupes :");
		cout << " 4 / Combien y a t-il d'etages : "; cin >> nbEtages; SecuriserInt(nbEtages, " 4 / Combien y a t-il d'etages :");
		cout << endl;


		// Sécurisation des saisies négatives, par une mise en valeur absolue
		SecuriserNeg();

		// Initialisation dynamique
		nbPlaceSetage = new int[nbEtages];
		listeEtages = new Etage[nbEtages];
		int nbSalles = 0;
		cout << "\\   Etages   \\" << endl;
		for (int i = 0; i < nbEtages; i++)
		{
			cout << "	Combien y a t-il de salles a rajouter : ";
			cin >> nbSalles;
			cout << "	Combien y a t-il de places a l'etage " << i << ": ";
			cin >> nbPlaceSetage[i];
			nbPlacesTotal += nbPlaceSetage[i];
			cout << nbPlaceSetage[i];
			// Creation d'un etage et ajout à la liste
			Etage e(nbPlaceSetage[i], (int)((nbPlaceSetage[i] + 1) / 2));
			e.SetID(i);
			e.listeSalles = new Salle[nbSalles];
			e.SetNbSalles(nbSalles);
			for (int j = 0; j < nbSalles; j++)
			{
				e.listeSalles[j].SetLongueurX(GetLongueurResto());
				e.listeSalles[j].SetLongueurY(GetLargeurResto());
				e.listeSalles[j].SetNbChaises(e.GetNbChaises());
				e.listeSalles[j].SetNbTables(e.GetNbTables());
				e.listeSalles[j].AfficherInfos();	
				e.listeSalles[j].Generer();
			}
			//e.RepartirChaiseSetTablesDansChaqueSalle(); // On indique le nombre de chaises et de tables dans chaque salle
			for (int j = 0; j < nbSalles; j++)
			{
				if (i == 0)
					e.listeSalles[j].PlacerChaiseSetTables(PlacementType::compresse);	// puis on les place selon le mode de placement choisi ( cela décremente le nombre de chaises et de tables)
				else if (i == 1)
					e.listeSalles[j].PlacerChaiseSetTables(PlacementType::compresseCouloir);
				else if (i == 2)
					e.listeSalles[j].PlacerChaiseSetTables(PlacementType::espace);
				else if (i == 3)
					e.listeSalles[j].PlacerChaiseSetTables(PlacementType::fete);
				else
				{
					e.listeSalles[j].PlacerChaiseSetTables(PlacementType::compresse);	
				}
			}
			cout << "Nb personnes total " << GetNbPesonnesTotal();
			listeEtages[i] = e;
		}

		// Création des groupes
		EnregistrerGroupes(nbGroupes);

		for (int i = 0; i < nbEtages; i++)
		{
			listeEtages[i].RemplirSallesAvecPlacesEntrees(GetNbPesonnesTotal());	// On place les invités
		}




		int color = 0;
		// Création des étages
		//for (int i = 0; i < nbEtages; i++)
		//{
		//	// A simplifier
		//	Etage etage = listeEtages[i];
		//	for (int j = 0; j < etage.GetNbSalles(); j++)
		//	{
		//		cout << "Traitement etage : " << i << endl;
		//		cout << "j = " << j << endl;
		//		if (i == 0)			etage.listeSalles[j].PlacerChaiseSetTables(PlacementType::compresse);
		//		else if (i == 1)	etage.listeSalles[j].PlacerChaiseSetTables(PlacementType::compresseCouloir);
		//		else if (i == 2)	etage.listeSalles[j].PlacerChaiseSetTables(PlacementType::espace);
		//		else if (i == 3)	etage.listeSalles[j].PlacerChaiseSetTables(PlacementType::fete);
		//		if (i == 0) // Si premier etage
		//		{
		//			for (int idGrp = 0; idGrp < GetNbGroupes(); idGrp++)
		//			{
		//				if(idGrp == 0)			color = 13; // Couleur violette
		//				else if (idGrp == 1)	 color = 12; // Couleur rouge
		//				else if (idGrp == 2)	 color =  9; // Couleur bleue
		//				else if (idGrp == 3)	color = 14; // Couleur jaune
		//				etage.listeSalles[j].SetNbPlacesPrises(listeGroupes[idGrp].nb_pers_groupe(), color);
		//				if (listeGroupes[idGrp].nb_pers > 0)
		//					listeGroupes[idGrp].nb_pers--;
		//			}

		//		}
		//	}
		//}



	}
	else	// A refaire
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
			listeEtages[i].SetNbChaises(10 + i*10);
			int nbTables = (int)((listeEtages[i].GetNbChaises() + 1) / 2);
			listeEtages[i].SetNbTables(nbTables);
		}
		// On parcourt tous les étages d'indice j
		for (int i = 0; i < nbEtages; i++)
		{
			Etage etage = listeEtages[i];
			// On parcourt les salles d'indice i de cet étage d'indice j
			for (int j = 0; j < etage.GetNbSalles(); j++)
			{
				cout << "Traitement etage : " << i << "	|	";
				cout << "j = " << j << endl;

				// Pour l'instant, nous avons le même nombre de chaises par étage que dans une salle car il n'y a qu'une seule salle
				etage.listeSalles[j].SetNbChaises(etage.GetNbChaises());

				// On adapte le nombre de tables au nombre de chaises, en arrondissant la division à l'entier supérieur
				int nbTables = (int)((etage.GetNbChaises() + 1) / 2);
				etage.listeSalles[j].SetNbTables(nbTables);

				etage.listeSalles[j].Generer();

				// On effectue un placement différent pour chaque étage
				if (i == 0)etage.listeSalles[j].PlacerChaiseSetTables(PlacementType::compresse);
				else if (i == 1) etage.listeSalles[j].PlacerChaiseSetTables(PlacementType::compresseCouloir);
				else if (i == 2) etage.listeSalles[j].PlacerChaiseSetTables(PlacementType::espace);
				else if (i == 3) etage.listeSalles[j].PlacerChaiseSetTables(PlacementType::fete);
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
		nbPlaceSetage = _places;
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
			cout << "Etage " << i << " : " << listeEtages[i].GetNbChaises() << " places " << endl;
		}

		int c = 0;
		int i = 0;
		do
		{
			//system("cls"); //  On masque pour l'instant pour faire des tests
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