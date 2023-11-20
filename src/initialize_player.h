#ifndef INITIALIZE_PLAYER_H     //it is the initialize of the player 's function
#define INITIALIZE_PLAYER_H
#include "initialize.h"
Player *initialize_playerlist(int number_perplayer);
void insertlist(Player *head,int number_perplayer,int i);
Player *initialize(int n,int number_perplayer);
#endif


