#include <iostream>
using namespace std;

#ifndef cpp_Attaque_h
#define cpp_Attaque_h

class Attaque {
private:
    int type;            // 0 -> Pierre, 1 -> Feuille, 2 -> Ciseaux

public:
    // Constructeurs
    Attaque();          // Création d'une attaque aléatoire
    Attaque(int a);     // Création d'une attaque spécifique en fonction de l'entier passé en paramètre (0 -> Pierre, 1 -> Feuille, 2 -> Ciseaux)

    // Accesseurs
    int getTypeAttaque() const;     // Création de l'accesseur pour le type d'attaque qui retourne un entier correspondant au type d'attaque
    string getNomAttaque() const;   // Création de l'accesseur pour le nom de l'attaque qui retourne une chaîne de caractères correspondant au type d'attaque

    // Méthodes
    bool resoudreAttaque(Attaque &a) const;     // Création de la méthode resoudreAttaque qui prend en paramètre une référence vers une autre attaque et retourne un booléen indiquant si l'attaque courante gagne contre l'attaque passée en paramètre
    
};

#endif