#ifndef __ACTIONREACTION_H
#define __ACTIONREACTION_H

#include "Action.h"
class Joueur;
class ActionReaction : public Action
{
private:

public:
    ActionReaction(const std::string& nom, int cout);
    virtual ~ActionReaction();
    
    void afficher() const override;
    virtual bool reagir(Joueur& joueur) = 0;
};

#endif
