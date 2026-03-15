#include <iostream>
using namespace std;

#include "Ours.h"

void Ours::setAttaque() {       // Création du mutateur pour l'ours qui génère une attaque de type Feuille (1)
    typeAttaque = Attaque(1);   // Appel du constructeur d'Attaque qui génère une attaque de type Feuille (1)
}

void Ours::deplace(int maxX, int maxY)      // Création de la méthode deplacement pour l'ours
{
    int type = rand() % 8;                  // Génération d'un déplacement aléatoire parmi les 8 possibilités de déplacement en L
    switch (type)                           // En fonction du type de déplacement généré, on modifie les coordonnées x et y de l'ours 
    {
    case 1:                                 // Déplacement en L vers le haut à droite
        this->x = this->x+1;                // Le loup se déplace en x + 1 (vers la droite du plateau)
        if (this->x > maxX)                 // Vérification que l'ours ne dépasse pas la limite maxX (à droite du plateau)
        {
            this->x = this->x - maxX;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxX
        }
        this->y = this->y-2;                // Le loup se déplace en y - 2 (vers le haut du plateau)
        if (this->y < 0)                    // Vérification que l'ours ne dépasse pas la limite 0 (en haut du plateau)   
        {
            this->y = this->y + maxY;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxY
        }
        break;
    case 2:
        this->x = this->x-1;                // Le loup se déplace en x - 1 (vers la gauche du plateau)
        if (this->x < 0)                    // Vérification que l'ours ne dépasse pas la limite 0 (à gauche du plateau)
        {
            this->x = this->x + maxX;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxX
        }
        this->y = this->y-2;                // Le loup se déplace en y - 2 (vers le haut du plateau)  
        if (this->y < 0)                    // Vérification que l'ours ne dépasse pas la limite 0 (en haut du plateau)   
        {
            this->y = this->y + maxY;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxY
        }
        break; 
    case 3:
        this->x = this->x-2;                // Le loup se déplace en x - 2 (vers la gauche du plateau)
        if (this->x < 0)                    // Vérification que l'ours ne dépasse pas la limite 0 (à gauche du plateau)
        {
            this->x = this->x + maxX;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxX
        }
        this->y = this->y-1;                // Le loup se déplace en y - 1 (vers le haut du plateau)
        if (this->y < 0)                    // Vérification que l'ours ne dépasse pas la limite 0 (en haut du plateau)   
        {
            this->y = this->y + maxY;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxY
        }
        break;
    case 4:
        this->x = this->x-2;                // Le loup se déplace en x - 2 (vers la gauche du plateau)
        if (this->x < 0)                    // Vérification que l'ours ne dépasse pas la limite 0 (à gauche du plateau)
        {
            this->x = this->x = + maxX;     // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxX
        }
        this->y = this->y+1;                // Le loup se déplace en y + 1 (vers le bas du plateau)
        if (this->y > maxY)                 // Vérification que l'ours ne dépasse pas la limite maxY (en bas du plateau)
        {
            this->y = this->y - maxY;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxY
        }
        break;
    case 5:
        this->x = this->x-1;                // Le loup se déplace en x - 1 (vers la gauche du plateau)
        if (this->x < 0)                    // Vérification que l'ours ne dépasse pas la limite 0 (à gauche du plateau)
        {
            this->x = this->x = + maxX;     // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxX
        }
        this->y = this->y+2;                // Le loup se déplace en y + 2 (vers le bas du plateau)
        if (this->y > maxY)                 // Vérification que l'ours ne dépasse pas la limite maxY (en bas du plateau)
        {
            this->y = this->y - maxY;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxY
        }
        break;
    case 6:
        this->x = this->x+1;                // Le loup se déplace en x + 1 (vers la droite du plateau)
        if (this->x > maxX)                 // Vérification que l'ours ne dépasse pas la limite maxX (à droite du plateau)
        {
            this->x = this->x = - maxX;     // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxX
        }
        this->y = this->y+2;                // Le loup se déplace en y + 2 (vers le bas du plateau)
        if (this->y > maxY)                 // Vérification que l'ours ne dépasse pas la limite maxY (en bas du plateau)
        {
            this->y = this->y - maxY;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxY
        }
        break;
    case 7:
        this->x = this->x+2;                // Le loup se déplace en x + 2 (vers la droite du plateau)
        if (this->x > maxX)                 // Vérification que l'ours ne dépasse pas la limite maxX (à droite du plateau)
        {
            this->x = this->x = - maxX;     // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxX     
        }
        this->y = this->y+1;                // Le loup se déplace en y + 1 (vers le bas du plateau)
        if (this->y > maxY)                 // Vérification que l'ours ne dépasse pas la limite maxY (en bas du plateau)
        {
            this->y = this->y - maxY;       // Vérification que l'ours ne dépasse pas la limite maxY (en bas du plateau)
        }
        break;
    case 8:
        this->x = this->x+2;                // Le loup se déplace en x + 2 (vers la droite du plateau)
        if (this->x > maxX)                 // Vérification que l'ours ne dépasse pas la limite maxX (à droite du plateau)
        {
            this->x = this->x = - maxX;     // Si c'est le cas, on le fait revenir à l'autre bout du plateau moins maxX
        }
        this->y = this->y-1;                // Le loup se déplace en y - 1 (vers le haut du plateau)
        if (this->y < 0)                    // Vérification que l'ours ne dépasse pas la limite 0 (en haut du plateau)
        {
            this->y = this->y + maxY;       // Si c'est le cas, on le fait revenir à l'autre bout du plateau + maxY
        }
        break;
    default:
        break;
    }
}

Ours::Ours(int maxX, int maxY) : Animal(maxX, maxY)     // Création du constructeur pour l'ours qui appelle le constructeur de la classe mère Animal
{
    nom = "O";      // On donne le nom "O" à l'ours pour l'affichage sur le plateau
    setAttaque();   // On appelle le mutateur pour générer une attaque de type Feuille (1) pour l'ours
}

