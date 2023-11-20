
#include "initialize.h"
#include "game_start.h"
int decide_player(Player *head, int number_player, FILE *fp){
    int min = 100;
    int min_player = 0;
    char *colr[4] = {"spades", "hearts", "diamonds", "clubs"};
    char *numb[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen","King","Ace"};
    Player *current = head;//create a temp pointer to store the head of the player list
    Player *min_player_ptr = NULL;
    printf("Determining the playing order...\n");
    fprintf(fp,"Determining the playing order...\n");
    for (int i = 0; i < number_player; i++) {
        int random = rand()%head->count; // Randomly select a card from the player's hand
        printf("Player %d's card is %s %s\n", i + 1, colr[current->card[random].color], numb[current->card[random].number]);
        fprintf(fp,"Player %d's card is %s %s\n", i + 1, colr[current->card[random].color], numb[current->card[random].number]);
        if (current->card[random].color < min) {
            min = current->card[random].color;//store the min color
            min_player = i;//store the player who has the min card
            min_player_ptr = current;//store the player who has the min card
        } else if (current->card[random].color == min) {
            if (current->card[random].number < min_player_ptr->card[random].number) {
                min_player = i;
                min_player_ptr = current;
            }
        }
        current = current->next; // Move to the next node in the list
    }
    return min_player;
    // int max = -1;
    // int max_player = 0;
    // char *colr[4] = {"spades", "hearts", "diamonds", "clubs"};
    // char *numb[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King","Ace"};
    // Player *current = head;//create a temp pointer to store the head of the player list
    // Player *max_player_ptr = NULL;
    // printf("Determining the playing order...\n");
    // fprintf(fp,"Determining the playing order...\n");
    // for (int i = 0; i < number_player; i++) {
    //     int random = rand()%head->count; // Randomly select a card from the player's hand
    //     printf("Player %d's card is %s %s\n", i + 1, colr[current->card[random].color], numb[current->card[random].number]);
    //     fprintf(fp,"Player %d's card is %s %s\n", i + 1, colr[current->card[random].color], numb[current->card[random].number]);
    //     if (current->card[random].color > max) {
    //         max = current->card[random].color;//store the max color
    //         max_player = i;//store the player who has the max card
    //         max_player_ptr = current;//store the player who has the max card
    //     } else if (current->card[random].color == max) {
    //         if (current->card[random].number > max_player_ptr->card[random].number) {
    //             max_player = i;
    //             max_player_ptr = current;
    //         }
    //     }
    //     current = current->next; // Move to the next node in the list
    // }
    // return max_player;
}



