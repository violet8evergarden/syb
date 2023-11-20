#ifndef CARD_ABOUT_H
#define CARD_ABOUT_H    
#include "initialize.h"
void shuffle(Card *cards, int number_of_cards, FILE *fp);
void draw_card(Player *player, Deck_Of_Cards *deck, FILE *fp);
void initialize_cards(Card *cards, int d);
void sort_card(Card *cards, int size);
Deck_Of_Cards* init_deck(int d);
#endif


