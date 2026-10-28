#ifndef __CHAPELLE_H
#define __CHAPELLE_H

#include "Action.h"

class Chapelle : public Action {
public:
    Chapelle();
    ~Chapelle();
    
    void jouer(Partie& partie, Joueur& joueur) override;
};

#endif
