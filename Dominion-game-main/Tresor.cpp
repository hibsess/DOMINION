#include "Tresor.h"

Tresor::Tresor(const std::string& nom, int cout, int valeur)
    : Carte(nom, cout), m_valeur(valeur) {}

Tresor::~Tresor() {}

void Tresor::afficher() const {
    std::cout << "ceci est la carte " << getNom()
              << " qui donne " << m_valeur << " pieces" << std::endl;
}

const int& Tresor::getValeur() const {
    return m_valeur;
}