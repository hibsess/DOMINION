#ifndef __VILLAGE_H
#define __VILLAGE_H

#include "Action.h"

class Village : public Action {
public:
    Village();
    ~Village();
    
    void jouer(Partie& partie, Joueur& joueur) override;
};

#endif
