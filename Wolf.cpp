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

    this->x = this->x + typeX;          // Le loup se déplace en x + typeX (on ajoute pour que le déplacement soit vers la droite du plateau)
    if (this->x > maxX)                 // On vérifie que le loup ne dépasse pas la limite maxX (à droite du plateau)
    {
        this->x = this->x - maxX;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxX
    }
    else if (this->x < 0)               // On vérifie que le loup ne dépasse pas la limite 0 (à gauche du plateau)
    {
        this->x = this->x - maxX;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxX
    }

    this->y = this->y - typeY;          // Le loup se déplace en y - typeY (on soustrait pour que le déplacement soit vers le haut du plateau)
    if (this->y < 0)                    // On vérifie que le loup ne dépasse pas la limite 0 (en haut du plateau)   
    {
        this->y = this->y + maxY;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxY
    }
    else if (this->y > maxY)            // On vérifie que le loup ne dépasse pas la limite maxY (en bas du plateau)
    {
        this->y = this->y - maxY;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxY
    }
}

Wolf::Wolf(int maxX, int maxY) : Animal(maxX, maxY) // Création du constructeur pour le loup qui appelle le constructeur de la classe mère Animal
{
    nom = "W";      // On donne le nom "W" au loup pour l'affichage sur le plateau
    setAttaque();   // On appelle le mutateur pour générer une attaque aléatoire pour le loup
}

