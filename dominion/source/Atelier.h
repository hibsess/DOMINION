#ifndef __ATELIER_H
#define __ATELIER_H

#include "Action.h"

class Atelier : public Action {
public:
    Atelier();
    ~Atelier();
    
    void jouer(Partie& partie, Joueur& joueur) override;
};

#endif
