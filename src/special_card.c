#include "initialize.h"
#include "game_process.h"
void special_card(int *direction,int *isattack,int *isskip,int *draw_cards,Card *card_now){
    switch (card_now->number) {//if the card is special card, the game will do something special
        case 0:
        *isattack = 1;//if the card is attack card, the player will draw cards
        *draw_cards = *draw_cards + 2;
        break;
        case 1:
        *isattack = 1;
        *draw_cards = *draw_cards + 3;
        break;
        case 5:
        *draw_cards = 0;//if the card is defend card, the player will not draw cards
        *isattack = 0;
        break;
        case 9:
        *isskip = 1;//if the card is skip card, the player will be skipped
        break;
        case 10:
        *direction = 1 - *direction;//if the card is reverse card, the direction will be changed
        break;
        default://if the card is not special card, the game will do nothing
        *draw_cards = 0;
        *isattack = 0;
        *isskip = 0;
        break;
    }
}



