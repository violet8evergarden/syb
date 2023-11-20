#include"initialize.h"
#include "game_start.h"
void initialize_cards(Card *cards,int d){
    for (int i = 0;i<d*NUM_OF_CARDS;i++){
        cards[i].color = ((int)floor((double)i / 13)) % 4;
        cards[i].number = i%13;//initialize the cards
    }
}


