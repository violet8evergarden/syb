#include "initialize.h"
#include "game_start.h"
void decide_card(Deck_Of_Cards *deck,Deck_Of_Cards *used_card,Card *card_now,FILE *fp){
    char *colr[]={"Spades","Hearts","Diamonds","Clubs"};
    char *numb[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    Card *new_used_cards = (Card*)realloc(used_card->card, sizeof(Card) *(size_t) (used_card->count + 1));//add the card to the used_card
    if (new_used_cards == NULL) {
        printf("realloc for used_card failed\n");
        return;
    }
    used_card->card = new_used_cards;//add the card to the used_card
    used_card->card[used_card->count] = deck->card[deck->count - 1]; //add the card to the used_card
    used_card->count++;
    card_now->color = deck->card[deck->count - 1].color;//update the card_now
    card_now->number = deck->card[deck->count - 1].number;
    Card *new_deck_cards = realloc(deck->card, sizeof(Card) * (size_t)(deck->count - 1));//update the deck
    if (new_deck_cards == NULL) {
        perror("Failed to realloc memory for deck cards");
        exit(EXIT_FAILURE);
    }
    deck->card = new_deck_cards;//update the deck
    deck->count--;
    printf("\n");
    fprintf(fp,"\n");
    printf("-----The first card is %s %s-----\n",colr[card_now->color],numb[card_now->number]);
    fprintf(fp,"-----The first card is %s %s-----\n",colr[card_now->color],numb[card_now->number]);//print the first card
    printf("\n");
    fprintf(fp,"\n");
}


