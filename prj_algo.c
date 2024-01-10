#include "raylib.h"
#include <stdlib.h>
typedef struct Noeux {
    int info;
    struct Noeux *suivant;
} Noeux;
void dessiner_list_chaine(Noeux *tete) {
    Noeux *temp=tete;
    int index=0;
    int startX=10;
    int startY=10;

    while (temp!=NULL) {
        
        int boxWidth=120;
        int boxHeight=40;
        int textOffsetX=10;
        int textOffsetY=10;

        DrawText(TextFormat("%d", temp->info),startX +textOffsetX,startY+textOffsetY+index * (boxHeight + 10),20,BLACK);
        DrawRectangleLines(startX,startY+index * (boxHeight + 10),boxWidth,boxHeight,BLACK); 

        temp = temp->suivant;
        index++;
    }
}
int main(){



    return 0;
}