#ifndef __TOUR_H
#define __TOUR_H

// Tour gere un tour de jeu d'un joueur : ses 3 phases 
#include "Joueur.h"
#include "Reserve.h"


class Tour{
 private:
	int m_cmptActions; // compteur pour nbr d'actions
	int m_cmptAchats;
	int m_cmptPieces; // pieces disponibles pour acheter


public:
	Tour();
	void reinitialiser(); 

	void phaseAction(Partie& partie, Joueur& joueur);
	void phaseAchat(Partie& partie, Joueur& joueur);
    void phaseAjustement(Joueur& joueur);
    void ajouterActions(int nbr);
    void ajouterAchats(int nbr);
    void ajouterPieces(int nbr);
};
#endif

