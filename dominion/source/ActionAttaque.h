#ifndef __ACTIONATTAQUE_H
#define __ACTIONATTAQUE_H
//#include <iostream>
//#include <string>
#include "Action.h"
class ActionAttaque : public Action
{
private:
	
public:
	ActionAttaque(const std::string& nom , int cout);
	virtual ~ActionAttaque();
	void afficher() const override ;
	virtual void attaquer(Partie& partie, Joueur& victime) = 0;
	void jouer(Partie& partie, Joueur& joueur) override;  
};
#endif