#pragma once
#include <iostream>
#include <string>

using namespace std;

class Categorie
{

public:
	virtual string aff_categorie() = 0;
};

class Francais :public Categorie
{
public:
	string aff_categorie()
	{
		cout << "Ce restaurant est un restaurant francais" << endl;
		return "francais";
	}
};

class Italien :public Categorie
{
public:
	string aff_categorie()
	{
		cout << "Ce restaurant est un restaurant italien" << endl;
		return "Italien";
	}
};

class Japonnais :public Categorie
{
public:
	string aff_categorie()
	{
		cout << "Ce restaurant est un restaurant japonnais" << endl;
		return "Japonnais";
	}
};

class Indien :public Categorie
{
public:
	string aff_categorie()
	{
		cout << "Ce restaurant est un restaurant indien" << endl;
		return "Indien";
	}
};

class Chinois :public Categorie
{
public:
	string aff_categorie()
	{
		cout << "Ce restaurant est un restaurant chinois" << endl;
		return "Chinois";
	}
};

class FastFood :public Categorie
{
public:
	string aff_categorie()
	{
		cout << "Ce restaurant est un fast-food" << endl;
		return "FastFood";
	}
};

class Pizzeria :public Categorie
{
public:
	string aff_categorie()
	{
		cout << "Ce restaurant est une pizzeria" << endl;
		return "Pizzeria";
	}
};

class Kebab :public Categorie
{
public:
	string aff_categorie()
	{
		cout << "Ce restaurant est un kebab" << endl;
		return "Kebab";
	}
};

class Creperie :public Categorie
{
public:
	string aff_categorie()
	{
		cout << "Ce restaurant est une creperie" << endl;
		return "Creperie";
	}
};

class BarTapas :public Categorie
{
public:
	string aff_categorie()
	{
		cout << "Ce restaurant est un bar a tapas" << endl;
		return "BarTapas";
	}
};
