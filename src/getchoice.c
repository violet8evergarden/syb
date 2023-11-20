#include"initialize.h"
#include"game_process.h"
int getchoice(FILE *fp){
    int yes = 0;//yes or no
    char input[10] = {0};//get the input
    printf("\n");
    fprintf(fp,"\n");
    printf("You can play the card.\n Do you want to play it? (y/n)\n");
    fprintf(fp,"You can play the card.\n Do you want to play it? (y/n)\n");//ask the player if they want to play the card
    while (1) {
        scanf("%9s", input); 
        for(int i = 0; input[i]; i++){
            input[i] = (char)tolower(input[i]);//change the input to lower case
        }
        if (strcmp(input, "y") == 0 || strcmp(input, "yes") == 0) {//if the player want to play the card
            yes = 1;
            break; //
        } else if (strcmp(input, "n") == 0 || strcmp(input, "no") == 0) {//if the player don't want to play the card
            yes = 0;
            break; 
        } else {
            printf("Invalid input. Please answer 'y'/'n' or 'yes'/'no'.\n");
            fprintf(fp,"Invalid input. Please answer 'y'/'n' or 'yes'/'no'.\n");
        }
    }
    return yes;  
}


