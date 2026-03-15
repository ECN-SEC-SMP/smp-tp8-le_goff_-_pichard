#pragma once
#include <iostream>
using namespace std;

#include "Attaque.h"
#include "Animal.h"

class Lion : public Animal {            // Création de la classe Lion qui hérite de la classe Animal
public:     
    Lion(int maxX, int maxY);           // Constructeur qui appelle le constructeur de la classe mère Animal

    // Méthode
    void deplace(int maxX, int maxY);   // Création de la méthode deplacement pour le lion qui se déplace en diagonale

    // Mutateur
    void setAttaque() ;                 // Création du mutateur pour le lion qui génère une attaque aléatoire
};
