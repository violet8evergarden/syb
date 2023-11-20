#include "initialize.h"
#include "game_start.h"
void deal_cards(Player *head,Deck_Of_Cards *deck_store,int cardnumber_perplayer,int number_player,FILE *fp){
    printf("Deal cards...\n");
    fprintf(fp,"Deal cards...\n");
    Player *temp = head;//create a temp pointer to store the head of the player list
    for (int i = 0; i < number_player; i++) {
        for (int j = 0; j < cardnumber_perplayer; j++) {
            temp->card[j] = deck_store->card[deck_store->count-1];//add the card to the player's struct
            temp->count++;
            deck_store->count--;
            deck_store->card[deck_store->count].color = 0;
            deck_store->card[deck_store->count].number = 0;//delete the card in the deck
        }
        temp = temp->next;
    }  
    printf ("Deal cards successfully!\n");
    fprintf(fp,"Deal cards successfully!\n");
    printf ("\n");
    fprintf(fp,"\n");
}



