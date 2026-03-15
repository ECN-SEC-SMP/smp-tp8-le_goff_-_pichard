#include <iostream>
using namespace std;

#include "Pierre.h"

void Pierre::setAttaque() {            // Création du mutateur pour la pierre qui génère une attaque de type Pierre (0)
    typeAttaque = Attaque(0);          // Appel du constructeur d'Attaque qui génère une attaque de type Pierre (0)
}

void Pierre::deplace(int maxX, int maxY){   // Création de la méthode deplacement pour la pierre qui ne se déplace pas
    // Corps vide car pas de déplacement
}

Pierre::Pierre(int maxX, int maxY) : Animal(maxX, maxY) // Création du constructeur pour la pierre qui appelle le constructeur de la classe mère Animal
{
    nom = "P";      // On donne le nom "P" à la pierre pour l'affichage sur le plateau
    setAttaque();   // On appelle le mutateur pour générer une attaque de type Pierre (0) pour la pierre
}

