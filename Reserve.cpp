
// On cree les 17 piles une par une et on les remplit
// En mode rapide on met une seule carte par pile pour accélérer le jeu

#include "Reserve.h"
#include <iostream>
#include "Cuivre.h"
#include "Argent.h"
#include "Or.h"
#include "Domaine.h"
#include "Duche.h"
#include "Province.h"
#include "Malediction.h"
#include "Atelier.h"
#include "Bucheron.h"
#include "Chapelle.h"
#include "Douves.h"
#include "Festin.h"
#include "Jardins.h"
#include "Laboratoire.h"
#include "Sorciere.h"
#include "Village.h"
#include "Voleur.h"

Reserve::Reserve(int, bool modeRapide) {
    // nombre de cartes par pile 
    int nbCuivre = 60;
    int nbArgent = 40;
    int nbOr = 30;
    int nbDomaine = 24;
    int nbDuche = 12;
    int nbProvince = 8;
    int nbMalediction = 30;
    int nbJardins = 12;
    int nbRoyaume = 10;

    // mode rapide : une seule carte par pile
    if (modeRapide) {
        nbCuivre = nbArgent = nbOr = nbDomaine = nbDuche = nbProvince = nbMalediction = nbJardins = nbRoyaume = 1;
    }

    Pile* p;
    p = new Pile("Cuivre", 0);
    for (int i = 0; i < nbCuivre; i++) p->ajouter(new Cuivre());
    m_piles.push_back(p);

    p = new Pile("Argent", 3);
    for (int i = 0; i < nbArgent; i++) p->ajouter(new Argent());
    m_piles.push_back(p);

    p = new Pile("Or", 6);
    for (int i = 0; i < nbOr; i++) p->ajouter(new Or());
    m_piles.push_back(p);

    p = new Pile("Domaine", 2);
    for (int i = 0; i < nbDomaine; i++) p->ajouter(new Domaine());
    m_piles.push_back(p);

    p = new Pile("Duche", 5);
    for (int i = 0; i < nbDuche; i++) p->ajouter(new Duche());
    m_piles.push_back(p);

    p = new Pile("Province", 8);
    for (int i = 0; i < nbProvince; i++) p->ajouter(new Province());
    m_piles.push_back(p);

    p = new Pile("Malediction", 0);
    for (int i = 0; i < nbMalediction; i++) p->ajouter(new Malediction());
    m_piles.push_back(p);

    p = new Pile("Atelier", 3);
    for (int i = 0; i < nbRoyaume; i++) p->ajouter(new Atelier());
    m_piles.push_back(p);

    p = new Pile("Bucheron", 3);
    for (int i = 0; i < nbRoyaume; i++) p->ajouter(new Bucheron());
    m_piles.push_back(p);

    p = new Pile("Chapelle", 2);
    for (int i = 0; i < nbRoyaume; i++) p->ajouter(new Chapelle());
    m_piles.push_back(p);

    p = new Pile("Douves", 2);
    for (int i = 0; i < nbRoyaume; i++) p->ajouter(new Douves());
    m_piles.push_back(p);

    p = new Pile("Festin", 4);
    for (int i = 0; i < nbRoyaume; i++) p->ajouter(new Festin());
    m_piles.push_back(p);

    p = new Pile("Jardins", 4);
    for (int i = 0; i < nbJardins; i++) p->ajouter(new Jardins());
    m_piles.push_back(p);

    p = new Pile("Laboratoire", 5);
    for (int i = 0; i < nbRoyaume; i++) p->ajouter(new Laboratoire());
    m_piles.push_back(p);

    p = new Pile("Sorciere", 5);
    for (int i = 0; i < nbRoyaume; i++) p->ajouter(new Sorciere());
    m_piles.push_back(p);

    p = new Pile("Village", 3);
    for (int i = 0; i < nbRoyaume; i++) p->ajouter(new Village());
    m_piles.push_back(p);

    p = new Pile("Voleur", 4);
    for (int i = 0; i < nbRoyaume; i++) p->ajouter(new Voleur());
    m_piles.push_back(p);

}

Reserve::~Reserve() {
    int taille = m_piles.size();
    for (int i = 0; i < taille; i++) {
        delete m_piles[i];
    }
}

void Reserve::afficher() const {
    std::cout << "----------- RESERVE -----------" << std::endl;
    int taille = m_piles.size();
    for (int i = 0; i < taille; i++) {
        std::cout << i << "\t| prix " << m_piles[i]->getCout()
                  << " | reste " << m_piles[i]->getTaille()
                  << "\t| " << m_piles[i]->getNom() << std::endl;
    }
    std::cout << "-------------------------------" << std::endl;
}

Pile* Reserve::getPile(int numero) const {
    int taille = m_piles.size();
    if (numero < 0 || numero >= taille) {
        return nullptr;
    }
    return m_piles[numero];
}


void Reserve::afficher() const {
    std::cout << "Reserve :" << std::endl;
    int taille = m_piles.size();
    for (int i = 0; i < taille; i++) {
        std::cout << i << " - " << m_piles[i]->getNom();
        std::cout << " (cout " << m_piles[i]->getCout() << ")";
        std::cout << " reste " << m_piles[i]->getTaille() << std::endl;
    }
}

// La pile Province est la pile numero 5
bool Reserve::provinceVide() const {
    if (m_piles[5]->getTaille() == 0) {
        return true;
    }
    return false;
}

// Compte cmb de piles sont vides.
int Reserve::pileVide() const {
    int cmpt = 0;
    for (size_t i = 0; i < m_piles.size(); i++) {
        if (m_piles[i]->getTaille() == 0) {
            cmpt = cmpt + 1;
        }
    }
    return cmpt;
}