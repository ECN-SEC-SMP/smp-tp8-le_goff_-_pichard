#include <iostream>
using namespace std;

#include "Lion.h"

void Lion::setAttaque() {               // Création du mutateur pour le lion qui génère une attaque aléatoire
    typeAttaque = Attaque();            // Appel du constructeur par défaut d'Attaque qui génère une attaque aléatoire
}

void Lion::deplace(int maxX, int maxY)  // Création de la méthode deplacement pour le lion qui se déplace en diagonale
{
    int type = rand() % 4;              // Génération d'un déplacement aléatoire parmi les 4 possibilités de déplacement en diagonale
    switch (type)                       // En fonction du type de déplacement généré, on modifie les coordonnées x et y du lion
    {
    case 1:
        this->x = this->x+1;            // Le lion se déplace en x + 1 (vers la droite du plateau)
        if (this->x > maxX)             // Vérification que le lion ne dépasse pas la limite maxX (à droite du plateau)
        {
            this->x = this->x - maxX;   // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxX
        }   
        this->y = this->y-1;            // Le lion se déplace en y - 1 (vers le haut du plateau)
        if (this->y < 0)                // Vérification que le lion ne dépasse pas la limite 0 (en haut du plateau)
        {
            this->y = this->y + maxY;   // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxY
        }
        break;
    case 2:
        this->x = this->x-1;            // Le lion se déplace en x - 1 (vers la gauche du plateau)
        if (this->x < 0)                // Vérification que le lion ne dépasse pas la limite 0 (à gauche du plateau)
        {
            this->x = this->x + maxX;   // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxX
        }
        this->y = this->y-1;            // Le lion se déplace en y - 1 (vers le haut du plateau)
        if (this->y < 0)                // Vérification que le lion ne dépasse pas la limite 0 (en haut du plateau)
        {
            this->y = this->y + maxY;   // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxY
        }
        break;
    case 3:
        this->x = this->x-1;            // Le lion se déplace en x - 1 (vers la gauche du plateau)
        if (this->x < 0)                // Vérification que le lion ne dépasse pas la limite 0 (à gauche du plateau)
        {
            this->x = this->x + maxX;   // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxX
        }
        this->y = this->y+1;            // Le lion se déplace en y + 1 (vers le bas du plateau)
        if (this->y > maxY)             // Vérification que le lion ne dépasse pas la limite maxY (en bas du plateau)
        {
            this->y = this->y - maxY;   // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxY
        }
        break;
    case 4:
        this->x = this->x+1;            // Le lion se déplace en x + 1 (vers la droite du plateau)
        if (this->x > maxX)             // Vérification que le lion ne dépasse pas la limite maxX (à droite du plateau)
        {
            this->x = this->x - maxX;   // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxX
        }
        this->y = this->y+1;            // Le lion se déplace en y + 1 (vers le bas du plateau)
        if (this->y > maxY)             // Vérification que le lion ne dépasse pas la limite maxY (en bas du plateau)
        {
            this->y = this->y - maxY;   // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxY
        }
        break;
    default:
        break;
    }
}

Lion::Lion(int maxX, int maxY) : Animal(maxX, maxY) // Création du constructeur pour le lion qui appelle le constructeur de la classe mère Animal
{
    nom = "L";      // On donne le nom "L" au lion pour l'affichage sur le plateau
    setAttaque();   // On appelle le mutateur pour générer une attaque aléatoire pour le lion
}
