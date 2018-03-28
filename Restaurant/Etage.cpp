#include "Etage.h"
#include <iostream>
#include <string.h>
#include "Restaurant.h"
#include "Salle.h"
#include <iostream>



using namespace std;


 Etage::Etage(int _nbChaises, int _nbTables)
 {
	 nom = "Sans nom";
	 schema = "Pas de schema";
	 // Il faut trouver un moyen de faire passer en arguments NbChaises et NbTables
	 //Salle s(Restaurant::GetLongueurResto(), Restaurant::GetLargeurResto(), _nbChaises, _nbTables);
	 cout << "Longueur			:" << Restaurant::GetLongueurResto() << endl;
	 cout << "Largeur			:" <<  Restaurant::GetLargeurResto()  << endl;
	 cout << "Nombre de chaises : " << _nbChaises << endl;
	 cout << "Nombre de chaises : " << _nbTables << endl;
	 SetNbChaises(_nbChaises);
	 SetNbTables(_nbTables);
	 //s.SetEtage(this);
	 //listeSalles[0] = s;
 }

 void Etage::Affiche()
 {
	 cout << "\nNom etage					:	" << GetNom() << endl;
	 //cout << "Schema						:	" << (listeSalles[0].ConvertChar2DToString(listeSalles[0].GetSchema(), listeSalles[0].GetLongueurX(),listeSalles[0].GetLongueurY())) << endl;
	 cout << "Schema						:	";
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

 void Etage::RepartirChaiseSetTablesDansChaqueSalle()
 {
	 int nbChaiseSetage = GetNbChaises();
	 cout << "\nOn commence avec : " << nbChaiseSetage << " chaises dans la fonction de repartition\n";
	 // On indique le nombre de chaises pour chaque salle
	 for (int id = 0; id < GetNbSalles(); id++)
	 {
		 if (nbChaiseSetage > 0)
		 {
			 listeSalles[id].SetNbChaises(100);
		 }

		 // A la fin de la repartition des chaises, on calcule le nombre de tables allant avec
		 SetNbTables((int) (GetNbChaises()+1) /2 );
		 cout << " Nb Chaises Salle apres repartition: " << listeSalles[id].GetNbChaises() << endl;
		 cout << " Nb Tables  Salle apres repartition: " << listeSalles[id].GetNbTables() << endl;
	 }

 }

 void Etage::RemplirSallesAvecPlacesEntrees(int nbPersonnesTotal)	// Permet de remplir les salles dans l'ordre
 {

	 for (int idSalle = 0; idSalle < GetNbSalles(); idSalle++)
	 {
			 listeSalles[idSalle].SetNbPlacesPrises(nbPersonnesTotal);
	 }
 }

 void Etage::SetNbSalles(int nb)
 {
	 nbSalles = nb;
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
	 
 }