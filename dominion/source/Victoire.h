#ifndef __VICTOIRE_H
#define __VICTOIRE_H
#include <iostream>
#include <string>
#include "Carte.h"
class Joueur;
class Victoire : public Carte
{
private:
	int m_points;
public:
	Victoire(const std::string& nom , int cout, int points);
	~Victoire();
	void afficher() const override ;
	// besoin du code de hiba 
	//const int& getPoint(const Joueur& J) const; 
	virtual int getPoints(const Joueur& joueur) const;
};
#endif
