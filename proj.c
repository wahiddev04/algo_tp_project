#include "raylib.h"
#include <stdlib.h>


typedef struct Noeux {
    int info;
    struct Noeux *suivant;
} Noeux;


void add_element_list(Noeux** tete, int donné) {
    Noeux *n_noeux = (Noeux*)malloc(sizeof(Noeux));
    n_noeux->info = donné;
    n_noeux->suivant = NULL;

    if (*tete== NULL) {
        *tete = n_noeux;
    } else {
        Noeux *temp = *tete;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = n_noeux;
    }
}
