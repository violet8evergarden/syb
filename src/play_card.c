#include "initialize.h"
#include "game_process.h"
#include "game_end.h"
void play_card(Player *player, Deck_Of_Cards *used_card, int choice, FILE *fp) {
    char *colr[]={"Spades","Hearts","Diamonds","Clubs"};
    char *numb[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    Card *new_used_cards = (Card*)realloc(used_card->card, sizeof(Card) * (size_t)(used_card->count + 1));//the same as the function in draw_card.c
    if (new_used_cards == NULL) {
        printf("realloc for used_card failed\n");
        return;
    } 
    used_card->card = new_used_cards;
    used_card->card[used_card->count] = player->card[choice - 1]; //the same as the function in draw_card.c
    used_card->count++;
    for (int i = choice - 1; i < player->count - 1; i++) {
        player->card[i] = player->card[i + 1];
    }
    player->count--;
    if (player->count > 0) {
        Card *new_player_cards = (Card*)realloc(player->card, sizeof(Card) * (size_t)player->count);//the same as the function in draw_card.c
        if (new_player_cards == NULL) {
            printf("realloc for player card failed\n");
            return;
        }
        player->card = new_player_cards;
    } else {
        free(player->card);
        player->card = NULL;
    }
    printf("\n");
    fprintf(fp,"\n");
    printf("Player %d plays %s %s\n", player -> order, colr[used_card->card[used_card->count - 1].color], numb[used_card->card[used_card->count - 1].number]);
    fprintf(fp,"Player %d plays %s %s\n", player -> order, colr[used_card->card[used_card->count - 1].color], numb[used_card->card[used_card->count - 1].number]);
    printcard(used_card->card[used_card->count - 1].color, used_card->card[used_card->count - 1].number, fp);
    if (strcmp(numb[used_card->card[used_card->count - 1].number],"7") == 0){
        printf("defend!!!\n");
        fprintf(fp,"defend!!!\n");
        printf("\n");
        fprintf(fp,"\n");
    }
    
    else if (strcmp(numb[used_card->card[used_card->count - 1].number],"Jack") == 0)
    {
        printf("skip!!!\n");//print the special cards
        fprintf(fp,"skip!!!\n");
        printf("\n");
        fprintf(fp,"\n");
    }
    else if (strcmp(numb[used_card->card[used_card->count - 1].number],"Queen") == 0)
    {
        printf("reverse!!!\n");//print the special cards
        fprintf(fp,"reverse!!!\n");
        printf("\n");
        fprintf(fp,"\n");
    }
    else if (strcmp(numb[used_card->card[used_card->count - 1].number],"2") == 0)
    {
        printf("Plus 2\n");
        fprintf(fp,"Plus 2\n");
        printf("\n");
        fprintf(fp,"\n");
    }
    else if (strcmp(numb[used_card->card[used_card->count - 1].number],"3") == 0)
    {
        printf("Plus 3\n");
        fprintf(fp,"Plus 3\n");
        printf("\n");
        fprintf(fp,"\n");
    }
    else
    {
        printf("\n");
        fprintf(fp,"\n");
    }
}



