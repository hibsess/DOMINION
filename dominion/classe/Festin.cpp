#include "Festin.h"
#include "Partie.h"
#include "Rebut.h"
#include <iostream>
#include <string>

Festin::Festin() : Action("Festin", 4) {}
Festin::~Festin() {}

void Festin::jouer(Partie& partie, Joueur& joueur) {
    std::cout << "Tu utilises Festin. La carte est ecartee." << std::endl;
    
    partie.getRebut().ajouter(this); 

    std::cout << "Quelle carte veux-tu gagner (cout max 5) ? Tape son nom : ";
    std::string choix;
    std::cin >> choix;
    
    Carte* carteVoulue = partie.getReserve().retirer(choix);
    
    if (carteVoulue != nullptr && carteVoulue->getCout() <= 5) {
        joueur.recevoir(carteVoulue);
        std::cout << "Tu as recu " << carteVoulue->getNom() << std::endl;
    } else {
        std::cout << "Action annulee (carte trop chere ou introuvable)." << std::endl;
    }
}
