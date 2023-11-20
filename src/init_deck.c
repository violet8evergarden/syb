#include "initialize.h"
#include "game_start.h"
Deck_Of_Cards* init_deck(int d) {//initialize the deck
    Deck_Of_Cards* deck = (Deck_Of_Cards*)malloc(sizeof(Deck_Of_Cards));
    if (deck == NULL) {
        printf("malloc failed\n");
        exit(1);
    }
    deck->card = (Card*)malloc(sizeof(Card) * (size_t)d * (size_t)NUM_OF_CARDS);
    if (deck->card == NULL) {
        printf("malloc failed\n");
        free(deck);
        exit(1);
    }
    deck->count = d * NUM_OF_CARDS;
    return deck;
}






