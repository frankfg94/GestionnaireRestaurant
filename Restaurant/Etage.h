#pragma once
#include "Salle.h"
#include <iostream>
#include <string>

class Etage
{
private:
	std::string nom;
    int id;
	int nbChaises;
	int nbTables;
	int nbSalles;
	int nbPlacesPriseSetage;
public:
	Etage(int nbChaises = 0, int nbEtages = 0);							// Constructeur avec arguments optionnels
	void Affiche();														// Affiche les informations ainsi que le sch�ma d'une salle de cet �tage, pour l'instant, seule la premi�re salle est affich�e
	std::string GetNom();												// Obtient le nom de l'�tage
	int GetNbSalles();													// Obtient le  nombre de salles
	bool ResteDesPersonnesAPlacer();									// v�rifie s'il reste des chaises vides � cet �tage
	void RemplirSallesAvecPlacesEntrees(int nbPersonnesTotal);			// Place des personnes de mani�re automatique dans chaque salle
	int GetNbPlacesPrises();											// Obtient le nombre de places occup�es parmi toutes les salles
	int GetNbChaises();													// Obtient le nombre de chaises pour tout l'�tage
	int GetNbTables();													// Obtient le nombre de tables pour tout l'�tage
	int GetID();														// Obtient l'identifiant de l'�tage
	void SetNbSalles(int nb);											// Modifie le nombre de salles pour cet �tage
	void SetNom( std::string nomEt);									// Modifie le nom de l'�tage
	void SetID(int _id);												// Modifie l'identifiant de l'�tage
	void SetNbChaises(int _nbChaises);									// Modifie le nombre de chaises pour cet �tage
	void SetNbTables(int _nbTables);									// Modifie le nombre de tables pour cet �tage
	Salle* listeSalles;													// contient l'ensemble des salles pour cet �tage
	~Etage();															
};


	