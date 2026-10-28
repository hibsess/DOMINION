#include "Action.h"
#include <iostream>
Action::Action(const std::string& nom , int cout):Carte(nom,cout){}
Action::~Action(){}
void Action::afficher() const {
	std::cout << "ceci est la carte " << getNom() << std::endl;
}
