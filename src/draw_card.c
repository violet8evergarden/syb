#include "initialize.h"
#include "card_about.h"
#include "game_end.h"
void draw_card(Player *player, Deck_Of_Cards *deck,FILE *fp) {
    char *colr[]={"Spades","Hearts","Diamonds","Clubs"};
    char *numb[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    Card *new_player_cards = realloc(player->card, sizeof(Card) *(size_t) (player->count + 1));//add the card to the player
    if (new_player_cards == NULL) {
        perror("Failed to realloc memory for player cards");
        exit(EXIT_FAILURE);
    }
    player->card = new_player_cards;//add the card to the player
    player->card[player->count] = deck->card[deck->count - 1];//add the card to the player
    player->count++;

    
    Card *new_deck_cards = realloc(deck->card, sizeof(Card) * (size_t)(deck->count - 1));//update the deck
    if (new_deck_cards == NULL) {
        perror("Failed to realloc memory for deck cards");
        exit(EXIT_FAILURE);
    }
    deck->card = new_deck_cards;//update the deck
    deck->count--;

    printf("Player %d draws %s %s\n", player->order, colr[player->card[player->count - 1].color], numb[player->card[player->count - 1].number]);
    fprintf(fp,"Player %d draws %s %s\n", player->order, colr[player->card[player->count - 1].color], numb[player->card[player->count - 1].number]);
    printcard(player->card[player->count - 1].color, player->card[player->count - 1].number, fp);//print the card
    printf("\n");
    fprintf(fp,"\n");
}




