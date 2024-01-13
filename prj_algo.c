#include "raylib.h"
#include <stdlib.h>
typedef struct Noeux {
    int info;
    struct Noeux *suivant;
} Noeux;
void dessiner_list_chaine(Noeux *tete, int screenWidth, int screenHeight) {
    Noeux *temp = tete;
    int index = 0;
    
    // Position de départ au milieu de la fenêtre
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
int main(){

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

    return 0;


    return 0;
}