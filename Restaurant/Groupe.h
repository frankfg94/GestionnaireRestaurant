#ifndef GROUPE_H
#define GROUPE_H

#include <iostream>
#include <string>

class Groupe
{
    public:
        Groupe(int nombre_pers = 0, std::string _nom = "Aucun nom", int nombre_ref = 0);	// Constructeur avec param�tres facultatifs
        int nb_pers_groupe();																// Obtient le num�ro de r�servation
        int nb_ref_groupe();																// Obtient num�ro de r�f�rence
        std::string nom_resa_groupe();													
		int nb_pers;
		int nb_ref;
		std::string nom;

    private:
		// mettre toutes les variables ici Denis
};

#endif // GROUPE_H
