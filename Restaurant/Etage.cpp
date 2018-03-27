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
	 Salle s(Restaurant::GetLongueurResto(), Restaurant::GetLargeurResto(), _nbChaises, _nbTables);
	 cout << "Longueur" << Restaurant::GetLongueurResto();
	 cout << "Largeur" <<  Restaurant::GetLargeurResto();
	 setNbSalles(1);
	 listeSalles = new Salle[10];
	 s.SetEtage(this);
	 listeSalles[0] = s;
 }

 void Etage::Affiche()
 {
	 cout << "\nNom etage					:	" << getNom() << endl;
	 //cout << "Schema						:	" << (listeSalles[0].ConvertChar2DToString(listeSalles[0].GetSchema(), listeSalles[0].GetLongueurX(),listeSalles[0].GetLongueurY())) << endl;
	 cout << "Schema						:	"; listeSalles[0].Afficher() ;
	 cout << "Nombre de tables Etage		:	" << getNbTables() << endl;
	 cout << "Nombre de chaises Etage		:	" << getNbChaises() << endl;
	 cout << "Nombre de tables Salle		:	" << listeSalles[0].GetNbTables() << endl;
	 cout << "Nombre de chaises Salle		:	" << listeSalles[0].GetNbChaises() << endl;
	 cout << "ID				 			:	" << getID() << endl;
 }

 std::string Etage::getNom()
 {
	 return nom;
 }

 int Etage::getNbSalles()
 {
	 return nbSalles;
 }

 void Etage::setNbSalles(int nb)
 {
	 nbSalles = nb;
 }

 void Etage::SetNbPlacesPrises(int nb)
 {
	 nbPlacesPrisesEtage = nb;
 }


 int Etage::GetNbPlacesPrises()
 {
	 return nbPlacesPrisesEtage;
 }

 int Etage::getNbChaises()
 {

	 return nbChaises;
 }

 int Etage::getNbTables()
 {
	 return nbTables;
 }

 void Etage::setNbChaises(int nb)
 {

	  nbChaises = nb;
 }

 void Etage::setNbTables(int nb)
 {
	 nbTables = nb;
 }

 int Etage::getID()
 {
	 return id;
 }

 void Etage::setID(int _id)
 {
	id = _id ;
 }



 Etage::~Etage()
 {
	 
 }