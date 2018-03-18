#include <iostream>
#include <string>
#include "Salle.h"

using namespace std;

Salle::Salle()
{
    coord_x = 0;
    coord_y = 0;
    nb_chaise = 0;
    nb_table = 0;
}

void Salle::aff_info_salle()
{
    cout << "La salle est de taille : "<< coord_x << "," << coord_y << "." << endl;
    cout << "elle possede :"<< nb_chaise << " chaises et " << nb_table << " tables." << endl;
}

void Salle::modif_salle()
{
    cout << "Taille de la salle:" << endl;
    cout << "x: ";
    cin >> coord_x;
    cout << "y: ";
    cin >> coord_y;
    cout << "Mobilier de la salle:" << endl;
    cout << "Nombre de chaise: ";
    cin >> nb_chaise;
    cout << "Nombre de table: ";
    cin >> nb_table;
}

void Salle::aff_salle()
{
    int y = coord_y;
    int x = coord_x;
    cout << "|";
    while (x > 0)
    {
        cout << "-";
        x--;
    }
    cout << "|" << endl;
    x = coord_x;
    while (y > 0)
    {
        cout << "|";
        while (x > 0)
        {
            cout << " ";
            x = x--;
        }
        cout << "|" << endl;
        x = coord_x;
        y = y--;
    }
    cout << "|";
    while (x > 0)
    {
        cout << "-";
        x = x--;
    }
    cout << "|" << endl;
}
