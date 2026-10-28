#include "Jardin.h"

Jardin::Jardin() : Victoire("Jardin", 4, 0) {}

Jardin::~Jardin() {}

int Jardin::getPoints(const Joueur& joueur) const {
    
    int totalCartes = joueur.getNombreTotalCartes(); 
    
    return totalCartes / 10; 
}
