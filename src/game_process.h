#ifndef GAME_PROCESS_H  //it is the process of the game 's function
#define GAME_PROCESS_H
#include "initialize.h"
void play_card(Player *player,Deck_Of_Cards *used_card,int choice,FILE *fp);
int can_playcard(Player *player,int number,int color,int isattack,int i);
void special_card(int *direction,int *isattack,int *isskip,int *draw_cards,Card *card_now);
// void processCard(int card_number, int *isattack, int *draw_cards, int *isskip, int *direction);
int getchoice(FILE *fp);
int make_choice(Player *player,Card card_now,int isattack,FILE *fp);


#endif


