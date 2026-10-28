#ifndef __CARTE_H
#define __CARTE_H
#include <iostream>
#include <string>
class Carte
{
private:
	std::string m_nom;
	int m_cout;
public:
	Carte(const std::string& nom , int cout);
	virtual ~Carte();
	virtual void afficher() const = 0 ;
	const std::string& getNom() const;
	const int& getCout() const; 
};
#endif