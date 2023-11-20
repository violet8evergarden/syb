// Purpose: This file contains the function prototypes for the functions
#ifndef INITIALIZE_H
#define INITIALIZE_H

#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<getopt.h>
#include<ctype.h>
#define EXIT_SUCCESS  0
#define NUM_OF_CARDS 52//the number of cards

typedef struct {
    int number;
    int color;
}Card;

typedef struct Player{
    Card *card;
    int count;
    int score;
    int order;
    struct Player *next;
    struct Player *prev;
}Player;

typedef struct {
    Card *card;
    int count;
}Deck_Of_Cards;

#endif



