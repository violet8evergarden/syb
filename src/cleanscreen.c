#include "game_end.h"
#include "initialize.h"
void cleanscreen(FILE *fp) {
    getchar();//clear the buffer
    printf("Press enter to continue\n");//ask the player to press enter to continue
    fprintf(fp,"Press enter to continue\n");
    getchar();
    #ifdef _WIN64
        system("cls");//clear the screen
    #elif _WIN32
        system("cls");
    #else
        system("clear");//clear the screen in different system
    #endif
}



