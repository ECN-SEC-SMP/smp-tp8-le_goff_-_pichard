#pragma once
#include <iostream>
using namespace std;

#include "Animal.h"

class Pierre : public Animal {          // Création de la classe Pierre qui hérite de la classe Animal
public:
    Pierre(int maxX, int maxY);         // Constructeur qui appelle le constructeur de la classe mère Animal

    // Méthode
    void deplace(int maxX, int maxY);   // Création de la méthode deplacement pour la pierre qui ne se déplace pas

    // Mutateur
    void setAttaque() ;                 // Création du mutateur pour la pierre qui génère une attaque de type Pierre (0)
};

