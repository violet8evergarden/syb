# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](<https://keepachangelog.com/e>  n/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [released]

## [1.1] - 2023-10-27

### Added

three struct: player , cards, deck of card
four functions

```c
void draw_card(Player *player,Deck_Of_Cards *deck,Used_Cards *used_card){
    player->count++;
    player->card[player->count] = deck->card[deck->count];//add the card to the player's struct

    deck->count--;
    deck->card[deck->count+1].color = 0;
    deck->card[deck->count+1].number = 0;//delete the card in the deck

    printf("You draw a card: ");
    printCard(&player->card[player->count]);//print the card
    printf("\n");


}
```

like this functions

### Changed

adjust the head file and origin file.

### Removed

none

## [1.2] - 2023-11-3

### Added

sort_card.c  
decide_player.c  
deal_card.c

### Changed

draw_card.c :
change the malloc and the index  
draw_card.c :change the index  
main.c :put the command into the main function  
command.c: removed  
shuffle.c:change the malloc

## unfixed

```c
    while (r > 0){
        printf( "Player %d's turn:\n", number_order + 1);
        printf("player %d has %d cards\n",number_order + 1,players[number_order].count);
        for (int i = 0; i < players[number_order].count; i++) {
            printf("%d %d\n",players[number_order].card[i].color,players[number_order].card[i].number);
        }
        printf("your choose the card order:");
        scanf("%d",&choice);
        play_card(&players[number_order], used_card,choice);//play the card
        switch (used_card->card[used_card->count-1].number) {
            case 12:
                direction = -direction;
                break;
            case 11:
                skip = 1;
                direction = 2 * direction;
                break;
            case 2:
                attack = attack + 2;
                break;
            case 3:
                attack = attack + 3;
                break;
            case 7:
                attack = 0;
                break;
            default:
                break;
        }

    }
        // play_card(&players[number_order], used_card);//play the card
        printf("play_card %d %d\n",players[number_order].card[players->count-1].color,players[number_order].card[players->count-1].number);

        
        for (int i = 0; i < players[number_order].count; i++) {
            for 
        }
```

it remain to be completed in m3

## [1.3] - 2023-11-16

### Added
 `initialize.h`: Header file for game initialization functions.*(struct and origin file)*
- `game_mode.h`: Defines the game modes and rules.
- `game_end.h`: Contains functions to handle the end of the game.
- `game_start.h`: Functions to start the game.
- `game_process.h`: Manages the game processes and player turns.
- `initialize_player.h`: Deals with player initialization.
- `card_about.h`: Includes definitions related to card properties and actions.
---
---

automatic.c  
can_playcard.c  
change_player.c  
cleanscreen.c  
decide_card.c  
decide_player.c  
getchoice.c  
init deck.c  
initialize_cards.c  
Initialize_playerlist.c  
make_choice.c  
mannual.c  
print_card.c  
special_card.c


I **add** more function to make the game completd.I devide the game into two mode.And I add functions about special card.

### Changed

sort_card.c  
decide_player.c  
deal_card.c  
draw_card.c  
play_card.c  
main.c  

I **change** the array by using pointer.And as for the player. I use list to store the information of the player.And I **add** the *next and *prev into the player's struct.So the function about the player should all be changed.

## Fixed
``` c
#include "initialize.h"
#include "initialize.h"
#include "game_mode.h"
#include "game_end.h"
#include "game_start.h"
#include "game_process.h"
#include "initialize_player.h"
#include "card_about.h"
int main(int argc, char *argv[]){
    srand((unsigned)time(NULL));
    struct option longopts[] = {
        {"help",no_argument,NULL,'h'},
        {"initial cards",required_argument,NULL,'c'},
        {"number",required_argument,NULL,'n'},
        {"round",required_argument,NULL,'r'},
        {"auto", no_argument, NULL, 'a'},
        {"log", required_argument, 0, 'l'},
        {"deck", required_argument, 0, 'd'},
        {0,0,0,0}
    };      
    int option;
    int n = 4;
    int r = 3;
    int c = 5;
    char *log = "onecard.log";
    int d = 2;
    int isauto = 0;
    while ((option = getopt_long(argc, argv, "hal:n:c:r:d:", longopts, NULL)) != -1) {
        switch (option) {
            case 'h':
                // Handle the --help option
                printf("Usage: %s [OPTIONS]\n", argv[0]);
                printf("Options:\n");
                printf("  -h| --help       Display this help message\n");
                printf("  -n| --number     Set the number of players\n");
                printf("  -r| --round      Set the number of rounds\n");
                printf("  -c| --initial    Set the number of initial cards\n");
                printf("  -a| --auto       Enable auto play mode\n");
                printf("  -l| --log        Set the log file\n");
                printf("  -d| --deck       Set the number of decks\n");
                exit(EXIT_SUCCESS);
            case 'c':
                c = atoi(optarg);
                break;// Handle the --initial cards option
            case 'n':
                // Handle the --number option
                n = atoi(optarg);
                break;
            case 'd':
                d = atoi(optarg);
                break;
            case 'a':
                isauto = 1;
                break;
            break;
            case 'l':
                log = optarg;
                break;
            case 'r':
                r = atoi(optarg);
                break;
            case '?':
                // Handle unrecognized options
                printf("Try '%s --help' for more information.\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    FILE *fp;
    fp = fopen(log,"w");
    if (fp == NULL) {
        printf("open file failed\n");
        exit(1);
    }
    fprintf(fp,"########################\n");
    fprintf(fp,"#                      #\n");
    fprintf(fp,"#  Welcome to One Card #\n");
    fprintf(fp,"#                      #\n");
    fprintf(fp,"########################\n");
    fprintf(fp,"\n");
    fprintf(fp, "---- Initial setup ----\n");
    fprintf(fp,"The number of players is %d\n",n);
    fprintf(fp,"The round of game is %d\n",r);
    fprintf(fp,"The number of cards per player is %d\n",c);
    fprintf(fp,"The number of decks is %d\n",d);
    fprintf(fp,"\n");
    if (isauto == 1){
        automatic(n,c,d,r,fp);
        return 0;
    }
    else{
        mannual(n,c,d,r,fp);
        return 0;
    }
    fclose(fp);
}
```

This is the main function and it can complete the whole project