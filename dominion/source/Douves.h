#ifndef __DOUVES_H
#define __DOUVES_H

#include "ActionReaction.h"

class Douves : public ActionReaction {
public:
    Douves();
    ~Douves();
    
    void jouer(Partie& partie, Joueur& joueur) override;
    bool reagir(Joueur& joueur) override;
};

#endif
