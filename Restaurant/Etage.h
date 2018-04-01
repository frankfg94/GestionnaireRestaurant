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
	void Affiche();														// Affiche les informations ainsi que le schéma d'une salle de cet étage, pour l'instant, seule la première salle est affichée
	std::string GetNom();												// Obtient le nom de l'étage
	int GetNbSalles();													// Obtient le  nombre de salles
	bool ResteDesPersonnesAPlacer();									// vérifie s'il reste des chaises vides à cet étage
	void RemplirSallesAvecPlacesEntrees(int nbPersonnesTotal);			// Place des personnes de manière automatique dans chaque salle
	int GetNbPlacesPrises();											// Obtient le nombre de places occupées parmi toutes les salles
	int GetNbChaises();													// Obtient le nombre de chaises pour tout l'étage
	int GetNbTables();													// Obtient le nombre de tables pour tout l'étage
	int GetID();														// Obtient l'identifiant de l'étage
	void SetNbSalles(int nb);											// Modifie le nombre de salles pour cet étage
	void SetNom( std::string nomEt);									// Modifie le nom de l'étage
	void SetID(int _id);												// Modifie l'identifiant de l'étage
	void SetNbChaises(int _nbChaises);									// Modifie le nombre de chaises pour cet étage
	void SetNbTables(int _nbTables);									// Modifie le nombre de tables pour cet étage
	Salle* listeSalles;													// contient l'ensemble des salles pour cet étage
	~Etage();															
};


	