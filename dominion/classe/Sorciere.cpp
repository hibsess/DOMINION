#include "Sorciere.h"
#include "Partie.h"
#include <iostream>

Sorciere::Sorciere() : ActionAttaque("Sorciere", 5) {}
Sorciere::~Sorciere() {}

void Sorciere::jouer(Partie& partie, Joueur& joueur) {
    // l'attaquant pioche 2 cartes
    joueur.piocher(2);
    
    ActionAttaque::jouer(partie, joueur);
}

void Sorciere::attaquer(Partie& partie, Joueur& victime) {
    // Cette fonction est appelée pour chaque victime non protégée
    std::cout << victime.getNom() << " subit l'attaque de la Sorciere ! " << std::endl;
    
    Carte* malediction = partie.getReserve().retirer("Malediction");
    
    if (malediction != nullptr) {
        victime.recevoir(malediction); // La victime prend le -1 point
        std::cout << " -> " << victime.getNom() << " recoit une Malediction." << std::endl;
    } else {
        std::cout << " -> Ouf, il n'y a plus de Malediction dans la reserve." << std::endl;
    }
}
