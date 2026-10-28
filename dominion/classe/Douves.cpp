#include "Douves.h"
#include "Partie.h"
#include <iostream>

Douves::Douves() : ActionReaction("Douves", 2) {}
Douves::~Douves() {}

// Quand la carte est jouée normalement pendant son tour
void Douves::jouer(Partie& partie, Joueur& joueur) {
    joueur.piocher(2);
}

// Quand la carte est révélée pour bloquer une attaque
bool Douves::reagir(Joueur& joueur) {
    // Renvoyer true signifie que la protection a fonctionné
    return true; 
}
