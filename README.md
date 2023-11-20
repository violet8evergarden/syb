# ENGR151 project2

## Author

Hteam:11

Name: Yiben Shao

Student ID: 523370910123

## Compiling and running

Code Quality :100%

NO error and run_time wrong

## Brief documentation

In One Card, a game played by n players over r rounds, players use d standard Poker decks, excluding Jokers. The game begins with each player receiving c cards after the decks are shuffled. Additionally, to decide the playing order, each player is dealt an extra card, with the player drawing the lowest rank starting the game; these extra cards are then discarded. Gameplay proceeds counter-clockwise, starting with a face-up card from the stock pile setting the initial rank and suit. Players must play a card matching the rank or suit of the previous card on their turn, discarding it into the discard pile. If unable to play, they must draw from the stock pile, which, if exhausted, is replenished by shuffling the discard pile. A round ends when a player discards all their cards, with others receiving penalties equal to their remaining hand's card count. After r rounds, the player with the lowest total score, calculated by summing these penalties, wins. Ties for the lowest score are possible, leading to multiple winners.

## Files and Modules

- `initialize.h`: Header file for game initialization functions.*(struct and origin file)*
- `game_mode.h`: Defines the game modes and rules.
- `game_end.h`: Contains functions to handle the end of the game.
- `game_start.h`: Functions to start the game.
- `game_process.h`: Manages the game processes and player turns.
- `initialize_player.h`: Deals with player initialization.
- `card_about.h`: Includes definitions related to card properties and actions.

## functions
automatic.c  
can_playcard.c  
change_player.c  
cleanscreen.c  
deal_cards.c  
decide_card.c  
decide_player.c  
draw_card.c  
getchoice.c  
init deck.c  
initialize_cards.c  
Initialize_playerlist.c  
main.c  
make_choice.c  
mannual.c  
play_card.c  
print_card.c  
shuffle.c  
sort_card.c  
special_card.c

## input

1. r: the round of the game
2. n: the number of the people
3. d: the number of deck
4. c: the number of cards per player

## output

The onecard.log

### Executing program

---

1. Use shift+right click to open windows powershell in the directory(windows)

2. Use terminal in the directory(linux)

You can open your terminal and into your file location and code the order
The order is :

`gcc -O2 -Werror -Wall -Wextra -Wconversion -Wno-unused-result -Wvla -pedantic -std=c11 main.c automatic.c sort_card.c shuffle.c deal_cards.c decide_player.c Initialize_playerlist.c initialize_cards.c play_card.c can_playcard.c draw_card.c decide_card.c processCard.c print_card.c change_player.c init_deck.c special_card.c cleanscreen.c mannual.c getchoice.c -g -o myprogrm`

Here:

`-O2 -Werror -Wall -Wextra -Wconversion -Wno-unused-result -Wvla -pedantic -std=c11` is to test if the code quality satisfies

`main.c automatic.c sort_card.c shuffle.c deal_cards.c decide_player.c Initialize_playerlist.c initialize_cards.c play_card.c can_playcard.c draw_card.c decide_card.c processCard.c print_card.c change_player.c init_deck.c special_card.c cleanscreen.c mannual.c getchoice.c` And this is the function used in the project that you should in clude.

`-g -o` is used to run the project.

`myproject` is the file that you can use later.

now you can run the project by coding `./myproject`

this will run the main function.And it is the ***mannual*** mode

## Options

So here is some choice you can make.

`./myproject -h` It will jump the help information.

`./myproject -a` It will start the automatic mode

`./myproject -d number_of_d` decide the deck number of the card

`./myproject -c number_of_c` decide the number of cards per player

`./myproject -r number_of_r` decide the number of rounds they player

`./myproject -n number_of_n` decide the number of player

`./myproject -l name_of_logfile` decide the name of the log file

- **Game Modes**: The game has two mode

1. you can choose automatic mode.The player will play by them.
2. you can choose the manual mode.You can play by yourself.

## Basic Rules

### **Starting the Game**

- Each player is dealt c cards.(c can be decided by the player at the beginning of the game.you can add the -c number_perplayer to make it)
- The rest of the cards form a draw pile. The top card of the draw pile is turned over to start the discard pile. And it is the first card.
- And the cards has d decks also decided by the player.
- Player play one card,and the player whose card is the biggest is the first player to play the card.
- The direction is counterclockwise at beginning.

### **Gameplay**

- Players take turns matching a card from their hand.
- If the player can't play the card.He/She should draw one card from the drawdeck and jump his/her play turn.
- when the round end.The score of each player equals the score minus the number of cards in player's hand.

#### **Special Cards**

- ***Skip***: The next player is 'skipped'
- ***Reverse***: Reverses the direction of play.
- ***Draw Two***: The next player must draw two cards and miss their turn.However,the next player can play card if and only if he/she also has a plus 2 card.
- ***Draw Three***: The next player must draw Three cards and miss their turn.And it is same as the Draw Two.
- ***Defence***: defend the attack(when a player should have drawn 2 or 3 cards,now he do not need to draw cards).
- **Regular Cards**:  
Any other card has no special effect and is only used to match the previous card's rank or suit

### **Winning the Game**

The first player to get rid of all their cards wins the game

## Bonus

### Introduction

This repository contains a part of a card game project where the printcard function is used to display card information both on the console and in a log file. The function handles the graphical representation of cards using ASCII art.  

### Features

- **ASCII Card Representation:** Graphically represents cards using ASCII characters.
- **Dual Output:** Outputs card information to both console and a file.
- **Support for Multiple Suits and Values:** Handles various card suits (Spades, Hearts, Diamonds, Clubs) and values (2-10, J, Q, K, A).

## Change log

see it in Changelog.md
