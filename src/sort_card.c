#include"initialize.h"
#include"card_about.h"
void sort_card(Card *cards,int size){//sort the cards
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {//sort the cards by number and color
            if (cards[j].number > cards[j+1].number) {
                Card temp = cards[j];
                cards[j] = cards[j+1];
                cards[j+1] = temp;
            }
            else if (cards[j].number == cards[j+1].number) 
            {
                if (cards[j].color > cards[j+1].color) {//if the number is the same, sort by color
                    Card temp = cards[j];
                    cards[j] = cards[j+1];
                    cards[j+1] = temp;
                }
            }
        }
    }
}




