#include "ActionReaction.h"
#include <iostream>

ActionReaction::ActionReaction(const std::string& nom, int cout)
    : Action(nom, cout) {}

ActionReaction::~ActionReaction() {}

void ActionReaction::afficher() const {
    Action::afficher();
    std::cout << "  (carte Reaction)" << std::endl;
}
