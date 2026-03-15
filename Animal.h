#pragma once
#include <iostream>
using namespace std;

#include "Attaque.h"

class Animal {           // Création de la classe Animal qui représente un animal sur le plateau de jeu
protected:
    string nom;          // Nom de l'animal 
    int x;               // Abscisse
    int y;               // Ordonnée
    bool vivant;         // État de vie de l'animal 
    Attaque typeAttaque; // Type d'attaque de l'animal 
    int maxX;            // Limite maximale en x du plateau de jeu
    int maxY;            // Limite maximale en y du plateau de jeu

public:
    // Constructeurs            
    Animal(int maxX, int maxY); // Constructeur qui initialise les paramètres de l'animal avec les valeurs passées en paramètre pour maxX et maxY
    virtual ~Animal() {}        // Destructeur virtuel pour permettre la destruction correcte des objets dérivés de la classe Animal

    // Méthodes
    bool attaque(Animal &a);    // Création de la méthode attaque qui prend en paramètre une référence vers un autre animal et retourne un booléen indiquant si l'attaque de l'animal courant gagne contre l'attaque de l'animal passé en paramètre
    virtual void deplace(int maxX, int maxY) =0 ;   // Virtuel pur

    // Accesseurs
    string getNom() const;      // Création de l'accesseur pour le nom de l'animal qui retourne une chaîne de caractères correspondant au nom de l'animal
    int getX() const;           // Création de l'accesseur pour l'abscisse de l'animal qui retourne un entier correspondant à la position en x de l'animal
    int getY() const;           // Création de l'accesseur pour l'ordonnée de l'animal qui retourne un entier correspondant à la position en y de l'animal
    bool getVivant() const;     // Création de l'accesseur pour l'état de vie de l'animal qui retourne un booléen indiquant si l'animal est vivant ou non
    Attaque getAttaque()const;  // Création de l'accesseur pour le type d'attaque de l'animal qui retourne un objet de type Attaque correspondant au type d'attaque de l'animal

    // Mutateurs
    void setVivant(bool v);         // Création du mutateur pour l'état de vie de l'animal qui prend en paramètre un booléen indiquant si l'animal est vivant ou non et modifie le paramètre vivant de l'animal en conséquence
    virtual void setAttaque() = 0;  // Virtuelle pure

};