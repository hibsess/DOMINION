#include "Rebut.h"


void Rebut::recevoirCarte(Carte* carte){
m_cartesEcartees.push_back(carte);
}

Rebut::Rebut() {
}

Rebut::~Rebut(){
int taille = m_cartesEcartees.size();
    for (int i = 0; i < taille; i++) {
        delete m_cartesEcartees[i];
    }
}
