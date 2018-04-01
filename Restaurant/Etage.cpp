#include "Etage.h"
#include <iostream>
#include <string.h>
#include "Restaurant.h"
#include "Salle.h"

using namespace std;


 Etage::Etage(int _nbChaises, int _nbTables)
 {
	 nom = "Sans nom";
	 cout << "//		Etage cree			//" << endl;
	 cout << "Longueur			: " << Restaurant::GetLongueurResto() << endl;
	 cout << "Largeur			: " <<  Restaurant::GetLargeurResto()  << endl;
	 SetNbChaises(_nbChaises);
	 SetNbTables(_nbTables);
 }

 void Etage::Affiche()
 {
	 cout << "\nNom etage					:	" << GetNom() << endl;
	 cout << "Schema						:	\n";
	 for (int i = 0; i < GetNbSalles(); i++)
	 {
					 listeSalles[i].Afficher(7);
					 cout << "Nombre de tables Salle		:	" << listeSalles[i].GetNbTables() << endl;
					 cout << "Nombre de chaises Salle		:	" << listeSalles[i].GetNbChaises() << endl;
	 }
	 cout << "Nombre de tables Etage		:	" << GetNbTables() << endl;
	 cout << "Nombre de chaises Etage		:	" << GetNbChaises() << endl;
	 cout << "ID				 			:	" << GetID() << endl;
 }

 std::string Etage::GetNom()
 {
	 return nom;
 }


 int Etage::GetNbSalles()
 {
	 return nbSalles;
 }

 bool Etage::ResteDesPersonnesAPlacer()
 {
	 if (GetNbPlacesPrises() < GetNbChaises())
	 {
		 return true;
	 }
	 return false;
 }

 void Etage::RemplirSallesAvecPlacesEntrees(int nbPersonnesTotal)	// Permet de remplir les salles dans l'ordre
 {

	 for (int idSalle = 0; idSalle < GetNbSalles(); idSalle++)
	 {
		 if (idSalle == 0)
		 {
			 cout << "NB PERSONNES A PLACER DANS PREMIERE SALLE : " << nbPersonnesTotal << endl;
			 listeSalles[0].SetNbPlacesPrises(nbPersonnesTotal);
			 nbPersonnesTotal -= listeSalles[0].GetNbPlacesPrises();	// On d�termine le nombre de personnes � placer dans la salle suivante
		 }
		 else if (idSalle == 1)
		 {
			 cout << "NB PERSONNES A PLACER DANS DEUXIEME SALLE : " << nbPersonnesTotal << endl;
			 listeSalles[1].SetNbPlacesPrises(nbPersonnesTotal);
			 nbPersonnesTotal -= listeSalles[1].GetNbPlacesPrises();	// On d�termine le nombre de personnes � placer dans la salle suivante
		 }
		 else if (idSalle == 2)
		 {
			 cout << "NB PERSONNES A PLACER DANS TROISIEME SALLE : " << nbPersonnesTotal << endl;
			 listeSalles[2].SetNbPlacesPrises(nbPersonnesTotal);
			 nbPersonnesTotal -= listeSalles[2].GetNbPlacesPrises();	// On d�termine le nombre de personnes � placer dans la salle suivante
		 }
		 else if (idSalle >= 3)
		 {
			 cout << "NB PERSONNES A PLACER DANS TROISIEME SALLE : " << nbPersonnesTotal << endl;
			 listeSalles[idSalle].SetNbPlacesPrises(nbPersonnesTotal);
			 nbPersonnesTotal -= listeSalles[idSalle].GetNbPlacesPrises();	// On d�termine le nombre de personnes � placer dans la salle suivante
		 }
	 }
 }

 void Etage::SetNbSalles(int nb)
 {
	 nbSalles = nb;
 }

 void Etage::SetNom(std::string nomEt)
 {
	 nom = nomEt;
 }




 int Etage::GetNbPlacesPrises()
 {
	 return nbPlacesPriseSetage;
 }

 int Etage::GetNbChaises()
 {

	 return nbChaises;
 }

 int Etage::GetNbTables()
 {
	 return nbTables;
 }

 void Etage::SetNbChaises(int nb)
 {
	  nbChaises = nb;
 }

 void Etage::SetNbTables(int nb)
 {
	 nbTables = nb;
 }

 int Etage::GetID()
 {
	 return id;
 }

 void Etage::SetID(int _id)
 {
	id = _id ;
 }



 Etage::~Etage()
 {
	 cout << "Etage supprime\n";
 }