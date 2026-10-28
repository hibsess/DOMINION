#include "Chapelle.h"
#include "Partie.h"
#include "Rebut.h"
#include <iostream>
#include <string>

Chapelle::Chapelle() : Action("Chapelle", 2) {}
Chapelle::~Chapelle() {}

void Chapelle::jouer(Partie& partie, Joueur& joueur) {
    std::cout << "Chapelle : Tu peux ecarter jusqu'a 4 cartes." << std::endl;
    
    int cartesEcartees = 0;
    
    while (cartesEcartees < 4) {
        std::cout << "Nom de la carte a ecarter (ou tape 'stop' pour arreter) : ";
        std::string choix;
        std::cin >> choix;
        
        if (choix == "stop") {
            break; // On sort de la boucle si le joueur ne veut plus écarter
        }
        
        // Il faut que ton binôme ait codé une méthode dans Joueur pour retirer UNE carte précise de la main
        // Exemple : retirerDeLaMain(string nomCarte) qui renvoie le pointeur de la carte
        Carte* carteAEcarter = joueur.retirerDeLaMain(choix);
        
        if (carteAEcarter != nullptr) {
            partie.getRebut().ajouter(carteAEcarter); // On la jette au rebut
            cartesEcartees++;
            std::cout << choix << " a ete ecartee au rebut." << std::endl;
        } else {
            std::cout << "Tu n'as pas de " << choix << " dans ta main ! Essaie encore." << std::endl;
        }
    }
}
