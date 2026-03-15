#pragma once
#include <iostream>
using namespace std;

#include "Attaque.h"
#include "Animal.h"

class Wolf : public Animal {            // Création de la classe Wolf qui hérite de la classe Animal
public:
    Wolf(int maxX, int maxY);           // Constructeur qui appelle le constructeur de la classe mère Animal

    // Méthode
    void deplace(int maxX, int maxY);   // Création de la méthode deplacement pour le loup

    // Mutateur
    void setAttaque() ;                 // Création du mutateur pour le loup qui génère une attaque aléatoire
};
