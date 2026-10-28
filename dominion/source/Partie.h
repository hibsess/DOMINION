#ifndef __PARTIE_H
#define __PARTIE_H
#include <string>
#include "Rebut.h"
#include "Joueur.h"
#include "Reserve.h"
#include "Tour.h"
#include <vector>
class Partie
{
private:
    std::vector<Joueur> m_joueurs;
    Reserve m_reserve;
    Rebut m_rebut;
    Tour m_tour;
    bool m_modeRapide;
public:
    Partie(const std::vector<std::string>& nomsJoueurs, bool modeRapide);
    ~Partie();
    void lancer();
    bool finDePartie() const;
    void annoncerVainqueur() const ;
    std::vector<Joueur>& getJoueurs();
    Reserve& getReserve() ;
    Rebut& getRebut() ;
    Tour& getTour() ;
    bool getModeRapide() const;
};
#endif