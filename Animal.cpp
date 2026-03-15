#include <iostream>
using namespace std;

#include "Animal.h"
#include "Attaque.h"

Animal::Animal(int maxX, int maxY)  // Création du constructeur pour la classe Animal qui initialise les paramètres de l'animal 
{
    this->maxX = maxX;              // Initialisation du paramètre maxX de l'animal avec la valeur passée en paramètre
    this->maxY = maxY;              // Initialisation du paramètre maxY de l'animal avec la valeur passée en paramètre
    this->vivant = true;            // Initialisation du paramètre vivant de l'animal à true pour indiquer que l'animal est vivant au départ
    this->x = rand() % maxX;        // Initialisation du paramètre x de l'animal avec une valeur aléatoire entre 0 et maxX pour positionner l'animal aléatoirement sur le plateau en x
    this->y = rand() % maxY;        // Initialisation du paramètre y de l'animal avec une valeur aléatoire entre 0 et maxY pour positionner l'animal aléatoirement sur le plateau en y
}

string Animal::getNom() const       // Création de l'accesseur pour le nom de l'animal qui retourne une chaîne de caractères correspondant au nom de l'animal
{
    return nom;                     // Retourne le nom de l'animal
}

int Animal::getX() const            // Création de l'accesseur pour l'abscisse de l'animal qui retourne un entier correspondant à la position en x de l'animal
{
    return this->x;                 // Retourne la position en x de l'animal
}

int Animal::getY() const            // Création de l'accesseur pour l'ordonnée de l'animal qui retourne un entier correspondant à la position en y de l'animal  
{
    return this->y;                 // Retourne la position en y de l'animal
}

bool Animal::getVivant() const      // Création de l'accesseur pour l'état de vie de l'animal qui retourne un booléen indiquant si l'animal est vivant ou non
{
    return this->vivant;            // Retourne l'état de vie de l'animal (true si vivant, false si mort)
}

Attaque Animal::getAttaque() const  // Création de l'accesseur pour le type d'attaque de l'animal qui retourne un objet de type Attaque correspondant au type d'attaque de l'animal
{
    return this->typeAttaque;       // Retourne le type d'attaque de l'animal
}

void Animal::setVivant(bool v)      // Création du mutateur pour l'état de vie de l'animal qui prend en paramètre un booléen indiquant si l'animal est vivant ou non et modifie le paramètre vivant de l'animal en conséquence
{
    this->vivant = v;               // Modifie l'état de vie de l'animal en fonction du booléen passé en paramètre (true pour vivant, false pour mort)
}

bool Animal::attaque(Animal &a)     // Création de la méthode attaque qui prend en paramètre une référence vers un autre animal et retourne un booléen indiquant si l'attaque de l'animal courant gagne contre l'attaque de l'animal passé en paramètre
{
    Attaque monAttaque = this->getAttaque();            // Récupération du type d'attaque de l'animal courant en appelant l'accesseur getAttaque() et stockage dans une variable monAttaque de type Attaque
    Attaque sonAttaque = a.getAttaque();                // Récupération du type d'attaque de l'animal passé en paramètre en appelant l'accesseur getAttaque() et stockage dans une variable sonAttaque de type Attaque
    return monAttaque.resoudreAttaque(sonAttaque);      // Appel de la méthode resoudreAttaque() de l'objet monAttaque en passant sonAttaque en paramètre pour déterminer si l'attaque de l'animal courant gagne contre l'attaque de l'animal passé en paramètre et retour du résultat (true si gagne, false si perd)
}
