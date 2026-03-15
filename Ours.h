#pragma once
#include <iostream>
using namespace std;

#include "Attaque.h"
#include "Animal.h"

class Ours : public Animal {            // Création de la classe Ours qui hérite de la classe Animal
public:
    Ours(int maxX, int maxY);           // Constructeur qui appelle le constructeur de la classe mère Animal

    // Méthode
    void deplace(int maxX, int maxY);   // Création de la méthode deplacement pour l'ours

    // Mutateur
    void setAttaque() ;                 // Création du mutateur pour l'ours qui génère une attaque de type Feuille (1)
};

