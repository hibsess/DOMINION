#include "Tour.h"
#include <iostream>

Tour::Tour() {
    reinitialiser();
}

void Tour::reinitialiser() {
    m_cmptActions = 1;
    m_cmptAchats = 1;
    m_cmptPieces = 0;
}
void Tour::ajouterActions(int nbr) {
    m_cmptActions = m_cmptActions+nb;
}

void Tour::ajouterAchats(int nbr) {
    m_cmptAchats = m_cmptAchats+nb;
}
void Tour::ajouterPieces(int nbr) {
    m_cmptPieces = m_cmptPieces+ nb;
}
//Phase1:
void Tour::phaseAction(Partie& partie, Joueur& joueur) {
    int choix = 0;
    while (m_cmptActions > 0 && choix != -1) {
        joueur.afficherMain();
        std::cout << "Actions : " << m_cmptActions << std::endl;
        std::cout << "Numero de la carte Action (-1 pour passer) : ";
        std::cin >> choix;

        if (choix != -1) {
            Carte* c = joueur.getCarteMain(choix);
            if (c != nullptr && c->estAction()) {
                m_cmptActions = m_cmptActions - 1;
                joueur.jouerCarte(choix);
                c->jouer(partie, joueur, *this);
            } else {
                std::cout << "Ce n'est pas une carte Action" << std::endl;
            }
        }
    }
}

// Phase 2:
void Tour::phaseAchat(Partie& partie, Joueur& joueur) {
    for (int i = joueur.getTailleMain() - 1; i >= 0; i--) {
        Carte* c = joueur.getCarteMain(i);
        if (c->getValeur() > 0) {
            m_cmptPieces = m_cmptPieces + c->getValeur();
            joueur.jouerCarte(i);
        }
    }

    while (m_cmptAchats > 0) {
        partie.getReserve().afficher();
        std::cout << "Pieces : " << m_cmptPieces << std::endl;
        std::cout << "Numero de la carte (-1 pour passer) : ";
        int choix;
        std::cin >> choix;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (choix == -1) {
            return;
        }

        Pile* p = partie.getReserve().getPile(choix);
        if (p != nullptr && p->getTaille() > 0 && p->getCout() <= m_cmptPieces) {
            m_cmptPieces = m_cmptPieces - p->getCout();
            m_cmptAchats = m_cmptAchats - 1;
            joueur.recevoirCarte(p->prendre());
        } else {
            std::cout << "Achat impossible" << std::endl;
        }
    }
}

// Phase 3 : la main et les cartes jouees vont dans la defausse et le joueur repioche
void Tour::phaseAjustement(Joueur& joueur) {
    joueur.defausser();
    joueur.piocher(5);
}