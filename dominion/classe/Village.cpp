#include "Village.h"
#include "Partie.h"
#include "Tour.h"

Village::Village() : Action("Village", 3) {}
Village::~Village() {}

void Village::jouer(Partie& partie, Joueur& joueur) {
    joueur.piocher(1); // Le joueur pioche 1 carte
    partie.getTour().ajouterActions(2); // +2 Actions pour ce tour
}
