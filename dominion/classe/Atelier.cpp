#include "Atelier.h"
#include "Partie.h"
#include "Reserve.h"
#include <iostream>
#include <string>

Atelier::Atelier() : Action("Atelier", 3) {}
Atelier::~Atelier() {}

void Atelier::jouer(Partie& partie, Joueur& joueur) {
    std::cout << "Atelier : Quelle carte veux-tu gagner (cout max 4) ? Tape son nom : ";
    std::string choix;
    std::cin >> choix;


    Carte* carteVoulue = partie.getReserve().retirer(choix); 

    if (carteVoulue != nullptr) {
        if (carteVoulue->getCout() <= 4) {
            std::cout << "Bravo, tu as recu " << carteVoulue->getNom() << " !" << std::endl;
            joueur.recevoir(carteVoulue); // La méthode de hiba pour mettre dans la défausse
        } else {
            std::cout << "Erreur : La carte coute trop cher (" << carteVoulue->getCout() << ")." << std::endl;
            // On remet la carte dans la réserve si elle était trop chère
            // partie.getReserve().ajouter(carteVoulue) selon comment la reserve de hiba marche
        }
    } else {
        std::cout << "Cette carte n'existe pas ou la pile est vide !" << std::endl;
    }
}
