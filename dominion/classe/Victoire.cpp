#include "Victoire.h"

Victoire::Victoire(const std::string& nom, int cout, int points)
    : Carte(nom, cout), m_points(points) {}

Victoire::~Victoire() {}

void Victoire::afficher() const {
    std::cout << "ceci est la carte " << getNom()
              << " qui donne " << m_points << " points" << std::endl;
}
int Victoire::getPoints(const Joueur&) const {
    return m_points;
}