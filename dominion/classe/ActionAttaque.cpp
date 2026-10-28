#include "ActionAttaque.h"
#include "Partie.h"
#include "Joueur.h"
#include <iostream>

ActionAttaque::ActionAttaque(const std::string& nom, int cout)
    : Action(nom, cout) {}

ActionAttaque::~ActionAttaque() {}

void ActionAttaque::afficher() const {
    Action::afficher();
    std::cout << "  (carte Attaque)" << std::endl;
}

void ActionAttaque::jouer(Partie& partie, Joueur& joueur) {

    //   parcourir tous les joueurs de la partie
    std::vector<Joueur>& joueurs = partie.getJoueurs();
    for(int i = 0; i < joueurs.size(); i++){
    	//   2. ignorer le joueur qui attaque
    	if(&joueurs[i] == &joueur)
    	{
    		continue;
    	}
    	std::cout << joueurs[i].getNom() << std::endl;
    	// si le joueur a une douve: 
    	bool estProtege = false;
    	// recuperer la main de la victime pour verifier si il a une douve 
    	std::vector<Carte> mainVictime = joueurs[i].getMain(); 
    	// On recupere les mains :
    	for(size_t j = 0; j < mainVictime.size(); j++) {
        	if(mainVictime[j].getNom() == "Douve") {
        		//laisser la victime se protéger (Douves) si elle le peut
            	estProtege = true;
            	break;
        	}
    	}
    	if(estProtege) {
        	std::cout << joueurs[i].getNom() << " bloque l'attaque avec une Douve !" << std::endl;
        	continue;
    	}
    	//sinon, appliquer l'effet propre à la carte
    	this->attaquer(partie, joueurs[i]);
	

    }
}