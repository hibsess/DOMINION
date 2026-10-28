#ifndef __VOLEUR_H
#define __VOLEUR_H

#include "ActionAttaque.h"

class Voleur : public ActionAttaque {
public:
    Voleur();
    ~Voleur();
    
    void attaquer(Partie& partie, Joueur& victime) override;
};

#endif
