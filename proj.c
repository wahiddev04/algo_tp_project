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
void Trie_a_bulle_list(Noeux *tete, int screenWidth, int screenHeight) {
    int perm;
    Noeux *ptr;
    Noeux *last = NULL;

    if (tete == NULL || tete->suivant == NULL) {
        return;
    }

    do {
        perm = 0;
        ptr = tete;

        while (ptr->suivant != last) {
            // Dessiner le contenu après chaque échange
                BeginDrawing();
                ClearBackground(RAYWHITE);
                dessiner_list_chaine(tete, screenWidth, screenHeight);
                EndDrawing();
                // Attendre avant de continuer
            double startTime = GetTime();
            while (GetTime() - startTime < 2.0) { }

            if (ptr->info > ptr->suivant->info) {
                // Échanger les données des nœuds
                int temp = ptr->info;
                ptr->info = ptr->suivant->info;
                ptr->suivant->info = temp;
                perm = 1;
            }

           

            ptr = ptr->suivant;
        }
        last = ptr;
    } while (perm);
}