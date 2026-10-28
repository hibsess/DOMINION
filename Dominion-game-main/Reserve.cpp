#include "Reserve.h"
#include <iostream>


//






















// Compte les piles qui n'ont plus de carte.
int Reserve::pilesVides() const {
    int cmpt = 0;
    for (size_t i = 0; i < m_piles.size(); i++) {
        if (m_piles[i]->getTaille() == 0) {
            cmpt = cmpt + 1;
        }
    }
    return cmpt;
}