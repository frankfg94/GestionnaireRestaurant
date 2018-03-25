#include "Etage.h"
#include <iostream>
#include <string.h>
#include "Restaurant.h"
#include "Salle.h"
#include <iostream>



using namespace std;

 Etage::Etage()
 {
	 nom = "Sans nom";
	 schema = "Pas de schema";
	 nbTables = 0;
	 nbChaises = 0;
 }

 void Etage::Affiche()
 {
	 cout << "\nNom etage			:	" << getNom() << endl;
	 cout << "Schema				:	" << getSchema() << endl;
	 cout << "Nombre de tables		:	" << getNbTables() << endl;
	 cout << "Nombre de chaises		:	" << getNbChaises() << endl;
	 cout << "ID					:	" << getID() << endl;
 }

 std::string Etage::getNom()
 {
	 return nom;
 }

 std::string Etage::getSchema()
 {
	 return schema;
 }

 int Etage::getNbChaises()
 {
	 return nbChaises;
 }

 int Etage::getNbTables()
 {
	 return nbTables;
 }

 int Etage::getID()
 {
	 return id;
 }

 void Etage::setID(int _id)
 {
	id = _id ;
 }

 void Etage::setNbChaises(int _nbChaises)
 {
	 nbChaises = _nbChaises ;
 }

 void Etage::setNbTables(int _nbTables)
 {
	 nbTables = _nbTables;
 }

 Etage::~Etage()
 {

 }