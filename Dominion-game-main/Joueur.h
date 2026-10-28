#ifndef __JOUEUR_H
#define __JOUEUR_H

#include<string>
#include <vector>
#include "Carte.h"

class Joueur {
private:
 	std::string m_nom;
    std::vector<Carte*> m_deck;
    std::vector<Carte*> m_main;
    std::vector<Carte*> m_defausse;
    std::vector<Carte*> m_zoneJeu;
    void melanger();  //on mélange que quand le deck est vide et qu’il faut piocher et au debut de la partie.

    
public:
    Joueur(std::string nom);
    ~Joueur();		
    void piocher(int nbre);
    void jouerCarte(int indice);
    void defausserCarte(int indice);// l'indice indique ici la position de la carte dans la main
    Carte* ecarterCarte(int indice);
    int compterPointsVictoire() const;
    int getNbCartesTotal() const;
    void recevoirCarte(Carte* carte);// lors d'achat d'une carte
    std::string getNom() const;
    
};
    
#endif
