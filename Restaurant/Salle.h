#pragma once
#include <iostream>
#include <string>
#include "Enum.h"

class Etage; // Forward Declaration

class Salle 
{
private:
	int longueurX;
	int longueurY;
	int nbChaises;
	int nbTables;
	int nombrePlacesPrisesSalle = 0;

	// Déclaration Forward, utilisation d'un pointeur obligatoire pour pouvoir faire des dépendances circulaires
	Etage* etage;
public:
	char** tab;	//structure de la salle
	Salle(int longX, int largY, int nbChaises, int nbTables);
	Salle();
	bool EstComplet();	// vérifie si la salle est complète (tout les places occupées)
	bool ResteDesChaisesAPlacer();	//vérifie s'il reste des places
	void SetLongueurX(int l);	//dimension de la salle
	void SetLongueurY(int l);	//dimension de la sallle
	void SetNbPlacesPrises(int nb);		// Déconseillé d'utiliser de manière manuelle, car déjà utilisé par la même fonction de type étage
	int GetNbPlacesPrises();	//nombre de places occupées dans la salle
	Etage* GetEtage();	//obtenir l'étage actuel
	void SetEtage(Etage * _etage);	//changer la salle d'étage 
	int GetLongueurX();	//obtenir la longueur du resto
	int GetNbChaises();	//obtenir le nombre de chaises dans la salle
	void SetNbChaises(int _nbChaises);	//indique le nombre de chaises pour la salle
	void SetNbTables(int _nbTables);	//indique le nombre de tables pour la salle
	int GetNbTables();	//obtenir le nombre de tables dans la salle
	int GetLongueurY();	//obtenir la longueur du resto
	void AfficherInfos();	//afficher les infos de la salle
	char** GetSchema();	//retourne tab
	static std::string ConvertChar2DToString(char ** tab, int sizeX, int sizeY);	//converti tab en string
	void SetSchema(char** schema);	//modifie tab
	void Modifier();	//demande à l'utilisateur de saisir les dimensions x et y et le nombre de tables et de chaises
	void ModifierierRapide(int longueurX, int largeurY, int nbChaises, int nbTables);	//idem mais sans saisie utilisateur
	void Afficher(int color);	//affichage final couleur d'une salle 
	void Generer();					// Génère une salle vide, indispensable pour pouvoir placer des tables
	void PlacerChaise(int x, int y);	//placement d'une chaise 
	void PlacerTable(int x, int y);		//placement d'une table
	char** PlacerChaiseSetTables(PlacementType t); // Permet de placer les chaises et tables selon une configuration prédéfinie, voir le fichier "Enum.h"
};
