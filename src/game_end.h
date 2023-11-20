#ifndef FAME_END_H   //it is the end of the game 's function
#define FAME_END_H
#include "initialize.h"
void free_playerlist(Player **head);
void printcard(int a, int b,FILE *fp);
void cleanscreen(FILE *fp);
void change_player(Player **player_now, int direction, int isskip);
#endif


