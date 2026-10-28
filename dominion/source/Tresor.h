#ifndef __TRESOR_H
#define __TRESOR_H
#include <iostream>
#include <string>
#include "Carte.h"
class Tresor : public Carte
{
private:
	int m_valeur;
public:
	Tresor(const std::string& nom , int cout, int valeur);
	~Tresor();
	void afficher() const override ;
	const int& getValeur() const; 
};
#endif