#ifndef SALLE_H_INCLUDED
#define SALLE_H_INCLUDED

#include <iostream>
#include <string>

class Salle
{
    private:
      int coord_x;
      int coord_y;
      int nb_chaise;
      int nb_table;	
    public:
        Salle();
        void aff_info_salle();
        void modif_salle();
		void modif_salle_fast(int longueurX, int largeurY, int nbChaises, int nbTables);
        void aff_salle();
};

#endif // SALLE_H_INCLUDED
