#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
#include "Attaque.h"
#include "Animal.h"
#include "Lion.h"
#include "Ours.h"
#include "Wolf.h"
#include "Pierre.h"
  
void affichagePlateau(vector<Animal*>& animaux, int maxX, int maxY) // Création de la fonction affichagePlateau qui prend en paramètre une référence vers un vecteur d'animaux et les dimensions du plateau de jeu pour afficher le plateau de jeu avec les animaux présents sur celui-ci
{
    cout << "|----|----|----|----|----|----|----|----|----|----|" << endl; // Ligne supérieure
    for (int j = 0; j < maxY; j++)      // Parcours de chaque ligne du plateau de jeu (de 0 à maxY-1)
    {
        cout << "|";        // Affichage du bord gauche de la ligne
        for (int i = 0; i < maxX; i++)      // Parcours de chaque colonne du plateau de jeu (de 0 à maxX-1)
        {
            string cellule = "    ";        // Initialisation de la variable cellule à une chaîne de caractères vide pour représenter une cellule vide du plateau de jeu
            for (Animal* a : animaux)       // Parcours de la liste des animaux pour vérifier s'il y a un animal vivant à la position (i, j) du plateau de jeu
            {
                if (a->getVivant() && a->getX() == i && a->getY() == j) // Si l'animal est vivant et que sa position correspond à la cellule (i, j) du plateau de jeu
                {
                    cellule = a->getNom() + "   ";  // Si c'est le cas, on remplace la variable cellule par le nom de l'animal suivi de trois espaces pour représenter l'animal dans la cellule du plateau de jeu
                    break;  // On sort de la boucle dès qu'on trouve un animal vivant à la position (i, j) du plateau de jeu, car il ne peut y en avoir qu'un seul dans une cellule donnée
                }
            }
            cout << cellule << "|";     // Affichage de la cellule suivie du bord droit de la cellule
        }
        cout << endl;   
        cout << "|----|----|----|----|----|----|----|----|----|----|" << endl;  // Affichage de la ligne de séparation entre les lignes du plateau de jeu
    }
}

void resoudreConflits(vector<Animal*>& animaux, int maxX, int maxY) // Création de la fonction resoudreConflits qui prend en paramètre une référence vers un vecteur d'animaux et les dimensions du plateau de jeu pour résoudre les conflits entre les animaux qui se trouvent sur la même cellule du plateau de jeu
{
    for (int i = 0; i < maxX; i++)      // Parcours de chaque colonne du plateau de jeu (de 0 à maxX-1)
    {
        for (int j = 0; j < maxY; j++)  // Parcours de chaque ligne du plateau de jeu (de 0 à maxY-1)
        {
            vector<Animal*> cellule;    // Création d'un vecteur de pointeurs vers des animaux pour stocker les animaux qui se trouvent sur la cellule (i, j) du plateau de jeu
            for (Animal* a : animaux)   // Parcours de la liste des animaux pour vérifier s'il y a des animaux vivants à la position (i, j) du plateau de jeu
            {
                if (a->getVivant() && a->getX() == i && a->getY() == j) // On vérifie si l'animal est vivant et que sa position correspond à la cellule (i, j) du plateau de jeu
                {
                    cellule.push_back(a);   // Si c'est le cas, on ajoute un pointeur vers l'animal dans le vecteur cellule pour représenter les animaux présents dans la cellule du plateau de jeu
                }
            }   
            while (cellule.size() > 1)      // Tant qu'il y a plus d'un animal dans la cellule (i, j) du plateau de jeu, il y a un conflit à résoudre entre les animaux présents dans cette cellule
            {
                int idx1 = rand() % cellule.size(); // Génération d'un nombre aléatoire entre 0 et la taille du vecteur cellule pour sélectionner un animal au hasard parmi les animaux présents dans la cellule du plateau de jeu
                int idx2;   // Déclaration d'une variable idx2 pour stocker l'indice du deuxième animal sélectionné pour le combat dans la cellule du plateau de jeu
                do
                {
                    idx2 = rand() % cellule.size(); // Génération d'un nombre aléatoire entre 0 et la taille du vecteur cellule pour sélectionner un deuxième animal au hasard parmi les animaux présents dans la cellule du plateau de jeu
                } while (idx2 == idx1); // Tant que le deuxième indice sélectionné est égal au premier indice sélectionné, on génère un nouveau nombre aléatoire pour idx2 afin de s'assurer que les deux indices sélectionnés correspondent à des animaux différents dans la cellule du plateau de jeu

                Animal* a1 = cellule[idx1]; // Récupération du pointeur vers le premier animal sélectionné pour le combat dans la cellule du plateau de jeu à partir de l'indice idx1
                Animal* a2 = cellule[idx2]; // Récupération du pointeur vers le deuxième animal sélectionné pour le combat dans la cellule du plateau de jeu à partir de l'indice idx2

                if (a1->attaque(*a2))   // Appel de la méthode attaque() du premier animal en passant le deuxième animal en paramètre pour déterminer si le premier animal gagne contre le deuxième animal dans le combat qui se déroule dans la cellule du plateau de jeu
                {
                    a2->setVivant(false);   // Si le premier animal gagne, on utilise le mutateur setVivant() du deuxième animal pour le marquer comme mort (false) 
                    cellule.erase(cellule.begin() + idx2);      // On supprime le pointeur vers le deuxième animal du vecteur cellule pour représenter la mort du deuxième animal dans la cellule du plateau de jeu
                }
                else
                {
                    a1->setVivant(false);   // Si le deuxième animal gagne, on utilise le mutateur setVivant() du premier animal pour le marquer comme mort (false)
                    cellule.erase(cellule.begin() + idx1);      // On supprime le pointeur vers le premier animal du vecteur cellule pour représenter la mort du premier animal dans la cellule du plateau de jeu
                }
            }
        }
    }
}

int compterVivants(vector<Animal*>& animaux)    // Création de la fonction compterVivants qui prend en paramètre une référence vers un vecteur d'animaux pour compter le nombre d'animaux vivants dans la liste des animaux
{
    int count = 0;  // Initialisation d'un compteur à 0 
    for (Animal* a : animaux)      // Parcours de la liste des animaux pour vérifier si chaque animal est vivant ou non
    {
        if (a->getVivant()) count++;    // Si l'animal est vivant, on incrémente le compteur de 1 
    }
    return count;   // Retourne le nombre d'animaux vivants dans la liste des animaux
}


int main()
{
    srand(time(NULL));  // Initialisation de la graine pour la génération de nombres aléatoires en utilisant l'heure actuelle pour garantir des résultats différents à chaque exécution du programme
    int maxX = 10;  // Définition de la variable maxX pour représenter la limite maximale en x du plateau de jeu
    int maxY = 10;  // Définition de la variable maxY pour représenter la limite maximale en y du plateau de jeu

    // Initialisation : 25% du plateau = 25 animaux, 6 de chaque type
    vector<Animal*> animaux;    // Création d'un vecteur de pointeurs vers des animaux pour stocker les animaux présents sur le plateau de jeu
    for (int i = 0; i < 6; i++) // Boucle pour ajouter 6 animaux de chaque type (Pierre, Wolf, Ours, Lion) dans la liste des animaux présents sur le plateau de jeu
    {
        animaux.push_back(new Pierre(maxX, maxY));  // Ajout d'un nouvel objet de type Pierre créé avec les dimensions du plateau de jeu (maxX, maxY) dans le vecteur animaux pour représenter un animal de type Pierre sur le plateau de jeu
        animaux.push_back(new Wolf(maxX, maxY));    // Ajout d'un nouvel objet de type Wolf créé avec les dimensions du plateau de jeu (maxX, maxY) dans le vecteur animaux pour représenter un animal de type Wolf sur le plateau de jeu
        animaux.push_back(new Ours(maxX, maxY));    // Ajout d'un nouvel objet de type Ours créé avec les dimensions du plateau de jeu (maxX, maxY) dans le vecteur animaux pour représenter un animal de type Ours sur le plateau de jeu
        animaux.push_back(new Lion(maxX, maxY));    // Ajout d'un nouvel objet de type Lion créé avec les dimensions du plateau de jeu (maxX, maxY) dans le vecteur animaux pour représenter un animal de type Lion sur le plateau de jeu
    }

    resoudreConflits(animaux, maxX, maxY);  // Appel de la fonction resoudreConflits() pour résoudre les conflits initiaux entre les animaux qui ont été placés aléatoirement sur le plateau de jeu lors de l'initialisation du jeu

    char rep = 'o';    // Initialisation d'une variable de type char pour stocker la réponse de l'utilisateur concernant la continuation du jeu
    int tour = 0;      // Initialisation d'une variable de type int pour stocker le nombre de tours joués

    while (rep == 'o' || rep == 'O')        // Boucle principale du jeu qui continue tant que l'utilisateur répond 'o' ou 'O' pour continuer à jouer       
    {
        if (compterVivants(animaux) == 0)   // Appel de la fonction compterVivants() pour vérifier s'il n'y a plus aucun animal vivant sur le plateau de jeu, ce qui signifie que le jeu est terminé
        {
            cout << "Plus aucun animal vivant !" << endl;   // Affichage d'un message indiquant que le jeu est terminé car il n'y a plus aucun animal vivant sur le plateau de jeu
            break;  // Sortie de la boucle principale du jeu pour terminer le programme
        }

        // Déplacer tous les animaux
        for (Animal* a : animaux)       // Parcours de la liste des animaux pour déplacer chaque animal vivant sur le plateau de jeu
        {
            if (a->getVivant())         // Vérification si l'animal est vivant avant de le déplacer
            {
                a->deplace(maxX, maxY); // Appel de la méthode deplace() de l'animal en passant les dimensions du plateau de jeu (maxX, maxY) pour déplacer l'animal sur le plateau de jeu en fonction de sa propre logique de déplacement définie dans sa classe dérivée (Pierre, Wolf, Ours, Lion)
            }
        }

        // Résoudre les conflits
        resoudreConflits(animaux, maxX, maxY);  // Appel de la fonction resoudreConflits() pour résoudre les conflits entre les animaux qui se trouvent sur la même cellule du plateau de jeu après le déplacement de tous les animaux

        // Afficher le plateau
        tour++; // Incrémentation du nombre de tours joués à chaque itération de la boucle principale du jeu
        cout << " --------------------- Tour " << tour << " --------------------" << endl;  // Affichage du numéro du tour actuel pour indiquer l'avancement du jeu
        affichagePlateau(animaux, maxX, maxY);  // Appel de la fonction affichagePlateau() pour afficher le plateau de jeu avec les animaux présents sur celui-ci après le déplacement et la résolution des conflits à chaque tour du jeu
        cout << "Il y a " << compterVivants(animaux) << " animaux vivants" << endl; // Appel de la fonction compterVivants() pour afficher le nombre d'animaux vivants restants sur le plateau de jeu à chaque tour du jeu

        cout << "Continuer ? (o/n) : "; // Demande à l'utilisateur s'il souhaite continuer à jouer après chaque tour du jeu en affichant un message et en attendant une réponse de l'utilisateur (o pour oui, n pour non)
        cin >> rep; // Lecture de la réponse de l'utilisateur pour déterminer s'il souhaite continuer à jouer ou non, et mise à jour de la variable rep en conséquence pour contrôler la continuation de la boucle principale du jeu
    }

    // Libération mémoire
    for (Animal* a : animaux) delete a; // Parcours de la liste des animaux pour libérer la mémoire allouée pour chaque animal en utilisant l'opérateur delete, ce qui est important pour éviter les fuites de mémoire dans le programme

    return 0;   // Retourne 0 pour indiquer que le programme s'est terminé avec succès
}




 
