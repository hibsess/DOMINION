#ifndef __FESTIN_H
#define __FESTIN_H

#include "Action.h"

class Festin : public Action {
public:
    Festin();
    ~Festin();
    
    void jouer(Partie& partie, Joueur& joueur) override;
};

#endif
