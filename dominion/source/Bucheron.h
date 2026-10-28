#ifndef __BUCHERON_H
#define __BUCHERON_H

#include "Action.h"

class Bucheron : public Action {
public:
    Bucheron();
    ~Bucheron();
    
    void jouer(Partie& partie, Joueur& joueur) override;
};

#endif
