#pragma once
#include <string>
class ObjetMobilier
{
private:
	std::string name = "Sans nom";
	int posX = 0;
	int posY = 0;
};

class Chaise : ObjetMobilier
{
};

class Table : ObjetMobilier
{

private:
	int longueurX;
	int longueurY;
};

class TableRonde : Table
{
public:
private:
	int rayon = 2;
};


class ChaiseLongue : Chaise
{
public:

private:
	int longueur = 3;
	bool vertical = false;
};