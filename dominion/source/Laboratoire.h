#ifndef __LABORATOIRE_H
#define __LABORATOIRE_H

#include "Action.h"

class Laboratoire : public Action {
public:
    Laboratoire();
    ~Laboratoire();
    
    void jouer(Partie& partie, Joueur& joueur) override;
};

#endif
