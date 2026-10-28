#include "Voleur.h"
#include "Partie.h"
#include <iostream>
#include <vector>

Voleur::Voleur() : ActionAttaque("Voleur", 4) {}
Voleur::~Voleur() {}

void Voleur::attaquer(Partie& partie, Joueur& victime) {
    std::cout << victime.getNom() << " se fait braquer par le Voleur !" << std::endl;
    
    // methode pour depiler une carte
    
    std::vector<Carte*> cartesRevelees;
    for(int i = 0; i < 2; i++) {
        Carte* c = victime.revelerCarteDuDeck(); 
        if(c != nullptr) {
            cartesRevelees.push_back(c);
        }
    }
    
    // On parcourt les cartes qu'on vient de révéler
    for(size_t i = 0; i < cartesRevelees.size(); i++) {
        std::cout << "Carte revelee : " << cartesRevelees[i]->getNom() << std::endl;
        
        std::string nom = cartesRevelees[i]->getNom();
        if(nom == "Cuivre" || nom == "Argent" || nom == "Or") {
            
            std::cout << "C'est un tresor ! Veux-tu le voler (v) ou le detruire (d) ? ";
            std::string choix;
            std::cin >> choix;
            
            if(choix == "v") {
                // L'attaquant prend la carte. 
                std::cout << "Tresor vole !" << std::endl;
                partie.getJoueurs()[partie.getTour().getCourant()].recevoir(cartesRevelees[i]); 
                // getIndex de l attaquant 
            } else {
                std::cout << "Tresor jete au rebut." << std::endl;
                partie.getRebut().ajouter(cartesRevelees[i]);
            }
            
        } else {
            // Si c'est pas un trésor, la victime la met dans sa défausse
            victime.recevoir(cartesRevelees[i]);
        }
    }
}
