#include "Laboratoire.h"
#include "Partie.h"
#include "Tour.h"

Laboratoire::Laboratoire() : Action("Laboratoire", 5) {}
Laboratoire::~Laboratoire() {}

void Laboratoire::jouer(Partie& partie, Joueur& joueur) {
    joueur.piocher(2); 
    partie.getTour().ajouterActions(1); 
}
