#include "Partie.h"
#include <iostream>

// L'ordre de la liste suit l'ordre de déclaration dans Partie.h
// (sinon -Wall affiche un warning -Wreorder)
Partie::Partie(const std::vector<std::string>& nomsJoueurs, bool modeRapide)
    : m_reserve(nomsJoueurs.size(), modeRapide),
      m_modeRapide(modeRapide)
{
    for (size_t i = 0; i < nomsJoueurs.size(); i++) {
        m_joueurs.push_back(Joueur(nomsJoueurs[i]));
    }
}

Partie::~Partie() {}

void Partie::lancer() {
    size_t courant = 0;

    while (!finDePartie()) {
        Joueur& joueur = m_joueurs[courant];   // & : le vrai joueur, pas une copie

        m_tour.reinitialiser();                // 1 action, 1 achat, 0 pièce
        m_tour.phaseAction(*this, joueur);
        m_tour.phaseAchat(*this, joueur);
        m_tour.phaseAjustement(*this, joueur);

        courant = (courant + 1) % m_joueurs.size();   // joueur suivant, en boucle
    }
    annoncerVainqueur();
}

bool Partie::finDePartie() const {
    return m_reserve.provinceVide() || m_reserve.nbPilesVides() >= 3;
}

void Partie::annoncerVainqueur() const {
    size_t meilleur = 0;

    for (size_t i = 0; i < m_joueurs.size(); i++) {
        std::cout << m_joueurs[i].getNom() << " : "
                  << m_joueurs[i].compterPoints() << " points" << std::endl;
    }
    for (size_t i = 1; i < m_joueurs.size(); i++) {
        int pi = m_joueurs[i].compterPoints();
        int pm = m_joueurs[meilleur].compterPoints();
        // égalité : celui qui a joué le moins de tours gagne
        if (pi > pm || (pi == pm && m_joueurs[i].getNbTours() < m_joueurs[meilleur].getNbTours())) {
            meilleur = i;
        }
    }
    std::cout << "Vainqueur : " << m_joueurs[meilleur].getNom() << std::endl;
}

std::vector<Joueur>& Partie::getJoueurs() 
{ 
	return m_joueurs; 
}

Reserve& Partie::getReserve()            
{
	return m_reserve; 
}

Rebut& Partie::getRebut()                
{
	return m_rebut; 
}

Tour& Partie::getTour()                   
{
	return m_tour; 
}

bool Partie::getModeRapide() const        
{ 
	return m_modeRapide; 
}