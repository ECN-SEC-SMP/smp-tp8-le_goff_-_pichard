#include <iostream>
using namespace std;

#include "Wolf.h"

void Wolf::setAttaque() {               // Création du mutateur pour le loup qui génère une attaque aléatoire
    this->typeAttaque = Attaque();      // Appel du constructeur par défaut d'Attaque qui génère une attaque aléatoire
}

void Wolf::deplace(int maxX, int maxY)  // Création de la méthode deplacement pour le loup
{
    int typeX = rand() % maxX;          // Génération d'un déplacement aléatoire en x
    int typeY = rand() % maxY;          // Génération d'un déplacement aléatoire en y

    this->x = typeX;
    this->y = typeY;
}

Wolf::Wolf(int maxX, int maxY) : Animal(maxX, maxY) // Création du constructeur pour le loup qui appelle le constructeur de la classe mère Animal
{
    nom = "W";      // On donne le nom "W" au loup pour l'affichage sur le plateau
    setAttaque();   // On appelle le mutateur pour générer une attaque aléatoire pour le loup
}

