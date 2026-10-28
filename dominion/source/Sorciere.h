#ifndef __SORCIERE_H
#define __SORCIERE_H

#include "ActionAttaque.h"

class Sorciere : public ActionAttaque {
public:
    Sorciere();
    ~Sorciere();
    
    void jouer(Partie& partie, Joueur& joueur) override;
    void attaquer(Partie& partie, Joueur& victime) override;
};

#endif
