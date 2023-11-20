#ifndef GAME_START_H  //it is the start of the game 's function
#define GAME_START_H
#include "initialize.h"
void deal_cards(Player *player,Deck_Of_Cards *deck,int cardnumber_perplayer,int number_player,FILE *fp);
int decide_player(Player *player,int number_player,FILE *fp);
void decide_card(Deck_Of_Cards *deck,Deck_Of_Cards *used_caed,Card *card_now,FILE *fp);
#endif


