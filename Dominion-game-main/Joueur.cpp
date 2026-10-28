#include "Joueur.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

Joueur::Joueur(std::string nom) {
    m_nom = nom;
}
std::string Joueur::getNom() const{
    return m_nom;
}

Joueur::~Joueur() {
    // on met toutes les cartes dans le deck puis on detruit
    defausser();
    melanger();

    int taille = m_deck.size();
    for (int i = 0; i < taille; i++) {
        delete m_deck[i];
    }
}

void Joueur::melanger(){
    // On remet les cartes de la defausse dans le deck
    int taille = m_defausse.size();
     for (int i = 0; i < taille; i++) {
        m_deck.push_back(m_defausse[i]);
    }
    // La defausse est mtn vide
    m_defausse.clear();

    // On melange le deck
    std::random_shuffle(m_deck.begin(), m_deck.end());
}

void Joueur::piocher(int nbre) {
    for (int i = 0; i < nbre; i++) {

        if (m_deck.empty()) {
    
            melanger();}
        if (m_deck.empty()) { return; }  
        m_main.push_back(m_deck.back());
        m_deck.pop_back();
    }}


void Joueur::defausserCarte(int indice) {
    int taille = m_main.size();//Le nombre de cartes en main

    if (indice < 0 || indice >= taille) {
        return;
    }
     m_defausse.push_back(m_main[indice]);//On lit l’adresse de la carte à cet indice et o,l’écrit à la fin de la défausse.
    m_main.erase(m_main.begin() + indice);}

    void Joueur::defausser() {
    int tailleMain = m_main.size();
    for (int i = 0; i < tailleMain; i++) {
        m_defausse.push_back(m_main[i]);
    }

    int tailleZone = m_zoneJeu.size();
    for (int i = 0; i < tailleZone; i++) {
        m_defausse.push_back(m_zoneJeu[i]);
    }
    m_main.clear();
    m_zoneJeu.clear();
}

    void Joueur::jouerCarte(int indice) {
    int taille = m_main.size(); // Le nombre de cartes en main

    if (indice < 0 || indice >= taille) {
        return;
    }

    // On lit l'adresse de la carte et on l'écrit à la fin de la zone de jeu
    m_zoneJeu.push_back(m_main[indice]);

    // On retire la carte de la main
    m_main.erase(m_main.begin() + indice);
}
void Joueur::recevoirCarte(Carte* carte) {
    m_defausse.push_back(carte);
}

Carte* Joueur::ecarterCarte(int indice) {
    int taille = m_main.size();
    if (indice < 0 || indice >= taille) {
        return nullptr;}

    Carte* carte = m_main[indice];
    m_main.erase(m_main.begin() + indice);
    return carte;
}

int Joueur::getNbCartesTotal() const {
    int total = m_deck.size() + m_main.size() + m_defausse.size() + m_zoneJeu.size();
    return total;
}
int Joueur::compterPointsVictoire() const {
    int total = 0;
    int nbCartes = getNbCartesTotal();

    // Les points du deck
    int tailleDeck = m_deck.size();
    for (int i = 0; i < tailleDeck; i++) {
        total = total + m_deck[i]->getPoints(nbCartes);
    }

    // Les points de la main
    int tailleMain = m_main.size();
    for (int i = 0; i < tailleMain; i++) {
        total = total + m_main[i]->getPoints(nbCartes);
    }

    // Les points de la défausse
    int tailleDefausse = m_defausse.size();
    for (int i = 0; i < tailleDefausse; i++) {
        total = total + m_defausse[i]->getPoints(nbCartes);
    }

    // Les points de la zone de jeu
    int tailleZoneJeu = m_zoneJeu.size();
    for (int i = 0; i < tailleZoneJeu; i++) {
        total = total + m_zoneJeu[i]->getPoints(nbCartes);
    }

    return total;
}

