#include "Groupe.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

Groupe::Groupe(int nombre_pers, std::string nom_groupe, int nombre_ref)
{
    nb_pers = nombre_pers;
    nom = nom_groupe;
    nb_ref = nombre_ref;
}
int Groupe::nb_pers_groupe()
{
    return nb_pers;
}
int Groupe::nb_ref_groupe()
{
    return nb_ref;
}

std::string Groupe::nom_resa_groupe()
{
	return std::string();
}

