#pragma once
#include <iostream>
#include <string>
#include "Enum.h"

class Etage; // Forward Declaration ou déclaration avancée

class Salle 
{
private:
	int longueurX;
	int LargeurY;
	int nbChaises;
	int nbTables;
	int nombrePlacesPrisesSalle = 0;

	// Déclaration Forward, utilisation d'un pointeur obligatoire pour pouvoir faire des dépendances circulaires
	Etage* etage;													// Etage auquel appartient cette salle
public:
	char** tab;	//structure de la salle
	Salle(int longX, int largY, int nbChaises, int nbTables);
	Salle();
	bool EstComplet();												// vérifie si la salle est complète (tout les places occupées)
	void SetLongueurX(int l);										//dimension de la salle X
	void SetLargeurY(int l);										//dimension de la salle Y
	void SetNbPlacesPrises(int nb);									// Déconseillé d'utiliser de manière manuelle, car déjà utilisé par la même fonction de type étage
	int GetNbPlacesPrises();										// Nombre de places occupées dans la salle
	Etage* GetEtage();												// Obtenir l'étage actuel
	void SetEtage(Etage * _etage);									// Changer la salle d'étage 
	int GetLongueurX();												// Obtenir la longueur du resto
	int GetNbChaises();												// Obtenir le nombre de chaises dans la salle
	void SetNbChaises(int _nbChaises);								// Indique le nombre de chaises pour la salle
	void SetNbTables(int _nbTables);								// Indique le nombre de tables pour la salle
	int GetNbTables();												// Obtenir le nombre de tables dans la salle
	int GetLargeurY();												// Obtenir la longueur du resto
	void AfficherInfos();											// Afficher les infos de la salle
	char** GetSchema();												//retourne le tableau 2D tab
	static std::string ConvertChar2DToString(char ** tab, int sizeX, int sizeY);	//convertir tab en string
	void SetSchema(char** schema);									// Modifie tab
	void Modifier();												// Demande à l'utilisateur de saisir les dimensions x et y et le nombre de tables et de chaises
	void ModifierierRapide(int longueurX, int largeurY, int nbChaises, int nbTables);	//idem mais sans saisie utilisateur
	void Afficher(int color);										// Affichage final couleur d'une salle 
	void Generer();													// Génère une salle vide, indispensable pour pouvoir placer des tables
	void PlacerChaise(int x, int y);								//placement d'une chaise aux coordonnées (x,y) indiquées
	void PlacerTable(int x, int y);									//placement d'une table aux coordonnées (x,y) indiquées
	char** PlacerChaiseSetTables(PlacementType t);					// Permet de placer les chaises et tables selon une configuration prédéfinie, voir le fichier "Enum.h"
};
