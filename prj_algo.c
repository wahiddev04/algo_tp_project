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


void dessiner_list_chaine(Noeux *tete, int screenWidth, int screenHeight) {
    Noeux *temp = tete;
    int index = 0;
    
    
    int startX = screenWidth / 2 - 80;
    int startY = screenHeight / 2 - 100;

    while (temp != NULL) {
        int boxWidth = 120;
        int boxHeight = 40;
        int textOffsetX = 10;
        int textOffsetY = 10;

        DrawText(TextFormat("%d", temp->info), startX + textOffsetX, startY + textOffsetY + index * (boxHeight + 10), 20, BLACK);
        DrawRectangleLines(startX, startY + index * (boxHeight + 10), boxWidth, boxHeight, BLACK);

        temp = temp->suivant;
        index++;
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

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Liste chaînée avec interface graphique Raylib");

    Noeux *tete = NULL;
    add_element_list(&tete, 6);
    add_element_list(&tete, 4);
    add_element_list(&tete, 9);
    add_element_list(&tete, 1);
    add_element_list(&tete, 5);

    while (!WindowShouldClose()) {
        
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Trie_a_bulle_list(tete, screenWidth, screenHeight);

        dessiner_list_chaine(tete, screenWidth, screenHeight);

        EndDrawing();
    }

    return 0;}




