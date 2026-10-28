#ifndef __ACTION_H
#define __ACTION_H
//#include <iostream>
//#include <string>
#include "Carte.h"
class Partie;
class Joueur;

class Action : public Carte
{
public:
	Action(const std::string& nom , int cout);
	virtual ~Action();
	void afficher() const override ;
	virtual void jouer(Partie& partie, Joueur& joueur) = 0;
};
#endif