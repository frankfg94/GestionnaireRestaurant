#include "restaurant.h"
#include <string>
#include <iostream>
#include <cmath>			// utilisé ici pour les valeurs absolues
#include <windows.h>		// utilisé pour changer la couleur des caractères
#include "Groupe.h"
#include "ChoixR.h"

using namespace std	;

// Saisie Sécurisée pour les variables type entier
void SecuriserInt(double inputVariable, string messageQuestion)		
{
	// on utilise cin.fail() pour détecter les erreurs de saisie
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\n>> Erreur : Merci d'entrer un entier\n\n";
		cout << messageQuestion;
		cin >> inputVariable;
	}

}


// Ensemble de fonctions Get() Set()
Groupe* Restaurant::listeGroupes;
int Restaurant::nbGroupes;
int Restaurant::GetNbGroupes()
{
	return nbGroupes;
}

int Restaurant::nbPersonnesPlacees;
int Restaurant::GetNbPersonnesPlacees()
{
	return nbPersonnesPlacees;
}

void Restaurant::SetNbPersonnesPlacees(int nb)
{
	nbPersonnesPlacees = nb;
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

// A partir d'ici sont mises les fonctions statiques

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

// Surcharge d'operateur output stream, afin d'afficher les caractéristiques d'un groupe g
ostream &operator<<(ostream &os, const Groupe &g)
{
	return os << "(nom:" << g.nom << "; nb:" << g.nb_pers << "; ref:" << g.nb_ref << ")\n\n";
}

void Restaurant::EnregistrerGroupes(int nbGroupes)
{
	// INITIALISATION
	listeGroupes = new Groupe[nbGroupes];
	for (int i = 0; i < nbGroupes; i++)
	{
		// On crée le groupe à ajouter
		Groupe g;
		g = listeGroupes[i];
		cout << "\\   Groupe " << i + 1 << "   \\" << endl;
		cout << "	a ) Entrer le nom du groupe : ";

		// cin.ignore() est necessaire pour ne pas avoir de problème d'affichage
		cin.ignore();
		getline(cin, g.nom);

		cout << "	b ) Entrer le numero de reference du groupe : "; cin >> g.nb_ref; SecuriserInt(g.nb_ref, "Numero de reference : ");
		cout << "	c ) Entrer le nombre de personnes dans le groupe : "; cin >> g.nb_pers; SecuriserInt(g.nb_pers, "Nombre de personnes : ");


		// Ne rajouter le dernier groupe, que si l'on a assez de places pour celui-ci
		if (g.nb_pers + nbPersonnesTotal> nbPlacesTotal)
		{
			cout << "Impossible d'ajouter plus de personnes :" << g.nb_pers + nbPersonnesTotal << " invites pour " << nbPlacesTotal << " places disponibles\n\n";
		}

		// A chaque création de groupe
		Restaurant::SetNbPesonnesTotal( GetNbPesonnesTotal() + g.nb_pers);
		cout << endl;
		listeGroupes[i] = g;

		// Affichage des attributs du groupe par surcharge d'opérateur
		cout << g;
	}
}

void Restaurant::SecuriserNeg()
{
	// utilisation de la fonction abs(int n) pour mettre en valeur absolue un nombre
	if(nbGroupes < 0)	nbGroupes = abs(nbGroupes);
	if (nbEtages < 0) nbEtages = abs(nbEtages);
	if (largeurResto < 0) largeurResto = abs(largeurResto);
	if (longueurResto < 0) longueurResto = abs(largeurResto);
}

void Restaurant::SaisirTypeRestaurant()
{
	string type;

	// Ensemble des types de restaurant
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
	int choixType = 0;

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
	cin >> choixType; SecuriserInt((int)choixType, "Veuillez entrer un entier pour le type de restaurant: ");
	if (choixType == 0 || choixType >= 11)
	{
		cout << "\nMauvaise saisie" << endl;
		return;
	}
	else if (choixType == 1)
	{
		type = afffr->aff_categorie();
	}
	else if (choixType == 2)
	{
		type = affIn->aff_categorie();
	}
	else if (choixType == 3)
	{
		type = affJp->aff_categorie();
	}
	else if (choixType == 4)
	{
		type = affIt->aff_categorie();
	}
	else if (choixType == 5)
	{
		type = affCh->aff_categorie();
	}
	else if (choixType == 6)
	{
		type = affFf->aff_categorie();
	}
	else if (choixType == 7)
	{
		type = affPi->aff_categorie();
	}
	else if (choixType == 8)
	{
		type = affKe->aff_categorie();
	}
	else if (choixType == 9)
	{
		type = affCr->aff_categorie();
	}
	else if (choixType == 10)
	{
		type = affBt->aff_categorie();
	}
	cout << "\nType enregistre : " + type << endl;

}


void Restaurant::Creer()
{
	cout << "---------------MENU DE GENERATION DU RESTAURANT-----------------" << endl << endl;
	SaisirTypeRestaurant();
	cout << " 1 / Quelle est la largeur du restaurant: "; cin >> largeurResto; SecuriserInt(largeurResto, " 1 / Quelle est la largeur du restaurant : ");
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
		std::string nomEtage;
		cout << "\n\\   Etages   \\" << endl;
		for (int i = 0; i < nbEtages; i++)	// i est l'étage actuel
		{
			cout << "			||   Etage   " << i << "||" << endl;
			cout << "						Combien y a t-il de salles a rajouter : ";
			cin >> nbSalles; SecuriserInt(nbSalles, "Reessayez:");
			cout << endl << endl;
			cout << "						Combien y a t-il de places a l'etage " << i << ": ";
			cin >> nbPlaceSetage[i]; SecuriserInt(nbSalles, "Reessayez:");
			nbPlacesTotal += nbPlaceSetage[i];
			cout << endl << endl;
			// Creation d'un etage et ajout à la liste
			Etage e(nbPlaceSetage[i], (int)((nbPlaceSetage[i] + 1) / 2));
			e.SetID(i);

			// initialisation du nombre de salles pour l'étage, en fonction de la saisie utilisateur de nbSalles
			e.listeSalles = new Salle[nbSalles];
			e.SetNbSalles(nbSalles);
			for (int j = 0; j < nbSalles; j++)
			{
				// précision des caractéristiques de la salle pour l'étage e
				e.listeSalles[j].SetLongueurX((int)GetLongueurResto());
				e.listeSalles[j].SetLargeurY((int)GetLargeurResto());
				e.listeSalles[j].SetNbChaises(e.GetNbChaises());
				e.listeSalles[j].SetNbTables(e.GetNbTables());
				e.listeSalles[j].AfficherInfos();	
				e.listeSalles[j].Generer();
			}
			for (int j = 0; j < nbSalles; j++)	// j est la salle actuelle, pour notre étage i
			{
				// puis on les place selon le mode de placement choisi ( cela décremente le nombre de chaises et de tables)
				if (i == 0)
					e.listeSalles[j].PlacerChaiseSetTables(PlacementType::compresse);	
				else if (i == 1)
					e.listeSalles[j].PlacerChaiseSetTables(PlacementType::compresseCouloir);
				else if (i == 2)
					e.listeSalles[j].PlacerChaiseSetTables(PlacementType::espace);
				else if (i == 3)
					e.listeSalles[j].PlacerChaiseSetTables(PlacementType::fete);
				else
				{
					e.listeSalles[i].PlacerChaiseSetTables(PlacementType::compresse);	
				}	

			}
			// on ajoute l'étage crée à la liste des étages
			listeEtages[i] = e;
		}

		// Création des groupes d'invités
		EnregistrerGroupes(nbGroupes);

		for (int i = 0; i < nbEtages; i++)
		{
			if (i == 0)
			{
				// On place les invités
				listeEtages[i].RemplirSallesAvecPlacesEntrees(GetNbPesonnesTotal());
			}
	
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



// Utilisation des flèches directionnelles, dont l'identifiant est associé à un entier

#define KEY_UP 72

#define KEY_DOWN 80

#define ESC 27

#include <conio.h> // permet d'utiliser la fonction _getch()


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

		// On met le menu d'affichage dans une boucle afin de pouvoir monter et descendre les étages autant de fois que l'on le souhaite.
		do
		{
			cout << "\n//		Etage		"<< i+1 <<  "/"<< nbEtages <<"		//\n";
			if (i == 0) cout << " \n\n>>			 Etage Initial!\n\n";
			else if (i >= nbEtages - 1) cout << "\n\n>>			 Etage Final!\n\n";
			listeEtages[i].Affiche();

			// On utilise _getch() pour obtenir la touche frappée
			switch ((c = _getch()))		
			{
			case KEY_UP:
			{
				// Si nous ne sommes pas déjà au dernier étage
				if (i < nbEtages -1)
				{
					// On monte d'un étage
					i++;
				}
				break;
			}

			case KEY_DOWN:
			{
				// Si nous ne sommes pas à l'état initial
				if ( i > 0 )
				{
					// On descend d'un étage
					i--;
				}
				break;
			}
			// Si la touche ne correspond pas on ne fait rien
			default:
			{
				break;
			}
			}
			c = 0; // on annule la valeur enregistree pour pouvoir en entrer une nouvelle
		} while (c != ESC);
		cout << "Touche ESC pressee, sortie de notre affichage etage par etage\n";

}