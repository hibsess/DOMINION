#ifndef __JARDIN_H
#define __JARDIN_H

#include "Victoire.h"
#include "Joueur.h" 

class Jardin : public Victoire {
public:
    Jardin();
    ~Jardin();
    
    // On redéfinit la méthode de calcul des points
    int getPoints(const Joueur& joueur) const override;
};

#endif
