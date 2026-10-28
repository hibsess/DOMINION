#include "Bucheron.h"
#include "Partie.h"
#include "Tour.h"

Bucheron::Bucheron() : Action("Bucheron", 3) {}

Bucheron::~Bucheron() {}

void Bucheron::jouer(Partie& partie, Joueur& joueur) {
    // On récupère l'objet Tour actuel depuis la partie
    Tour& tour = partie.getTour();
    
    // Le Bûcheron donne +1 Achat et +2 Pièces au tour en cours
    tour.ajouterAchats(1); 
    tour.ajouterPieces(2);
}
