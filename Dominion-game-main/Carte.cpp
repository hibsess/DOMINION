#include "Carte.h"
#include <iostream>
Carte::Carte(const std::string& nom , int cout): m_nom(nom), m_cout(cout){}
Carte::~Carte(){}
const std::string& Carte::getNom() const{
	return m_nom;
}
const int& Carte::getCout() const{
	return m_cout;
}