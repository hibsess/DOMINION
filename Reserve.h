#ifndef __RESERVE_H
#define __RESERVE_H


#include <vector>

// La reserve contient les 17 piles du jeu.
class Reserve {
private:
    std::vector<Pile*> m_piles;  

public:
    Reserve(int nbJoueurs, bool modeRapide);
    ~Reserve();
    void afficher() const; // montre le plateau de jeu
    Pile* getPile(int numero) const;    
    bool provinceVide() const;
    int pileVide() const;
};

#endif