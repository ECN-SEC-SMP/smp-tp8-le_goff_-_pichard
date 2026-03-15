#include <iostream>
#include "stdlib.h"
using namespace std;

#include "Attaque.h"

Attaque::Attaque()              //crée une attaque random
{
    this->type = rand() % 3;    // Génération d'un nombre aléatoire entre 0 et 2 pour déterminer le type d'attaque (0 -> Pierre, 1 -> Feuille, 2 -> Ciseaux)
}

Attaque::Attaque(int a)         //crée une attaque spécifique
{
    this->type = a;             // Affectation du type d'attaque spécifié par l'utilisateur (0 -> Pierre, 1 -> Feuille, 2 -> Ciseaux)
}


// Accesseurs
int Attaque::getTypeAttaque() const     // Création de l'accesseur pour le type d'attaque qui retourne un entier correspondant au type d'attaque
{
    return Attaque::type;               // Retourne le type d'attaque de l'objet courant
}

string Attaque::getNomAttaque() const   // Création de l'accesseur pour le nom de l'attaque qui retourne une chaîne de caractères correspondant au type d'attaque
{
    if (type == 0)                      // On vérifie si le type d'attaque est 0
    {
        return "Pierre";                // Si oui, on retourne "Pierre" comme nom de l'attaque
    }
    else if (type == 1)                 // On vérifie si le type d'attaque est 1
    {
        return "Feuille";               // Si oui, on retourne "Feuille" comme nom de l'attaque
    }
    else if (type == 2)                 // On vérifie si le type d'attaque est 2
    {
        return "Ciseaux";               // Si oui, on retourne "Ciseaux" comme nom de l'attaque
    }
    return "0";                         // Si le type d'attaque n'est pas 0, 1 ou 2, on retourne "0" pour indiquer une erreur
}

// Méthodes
bool Attaque::resoudreAttaque(Attaque &a) const         // Création de la méthode resoudreAttaque qui prend en paramètre une référence vers une autre attaque et retourne un booléen indiquant si l'attaque courante gagne contre l'attaque passée en paramètre
{
    if (this->type == 0 && a.getTypeAttaque() == 1)     // On vérifie si l'attaque courante est de type Pierre (0) et que l'attaque passée en paramètre est de type Feuille (1)
    {
        return false;                                   // Si oui, on retourne false car la Pierre perd contre la Feuille
    }

    if (this->type == 0 && a.getTypeAttaque() == 2)     // On vérifie si l'attaque courante est de type Pierre (0) et que l'attaque passée en paramètre est de type Ciseaux (2)
    {
        return true;                                    // Si oui, on retourne true car la Pierre gagne contre les Ciseaux          
    }

    if (this->type == 1 && a.getTypeAttaque() == 2)     // On vérifie si l'attaque courante est de type Feuille (1) et que l'attaque passée en paramètre est de type Ciseaux (2)
    {
        return false;                                   // Si oui, on retourne false car la Feuille perd contre les Ciseaux 
    }

    if  (this->type == 0 && a.getTypeAttaque() == 0     
        || this->type == 1 && a.getTypeAttaque() == 1
        || this->type == 2 && a.getTypeAttaque() == 2)  //  On vérifie si les deux attaques sont de même type (Pierre vs Pierre, Feuille vs Feuille ou Ciseaux vs Ciseaux)
    {
        int res = rand() % 2;  // Si oui, on génère un nombre aléatoire entre 0 et 1 pour déterminer le résultat en cas d'égalité 
        if (res == 1)          // On vérifie si le résultat est 1
        {
            return true;       // Si oui, on retourne true pour indiquer que l'attaque courante gagne en cas d'égalité
        }
        else
        {
            return false;      // Si non, on retourne false pour indiquer que l'attaque courante perd en cas d'égalité
        }
    }   
    return false;              // Si aucune des conditions précédentes n'est vérifiée, on retourne false pour indiquer que l'attaque courante perd contre l'attaque passée en paramètre
}
