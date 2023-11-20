#include "initialize.h"
#include "card_about.h"
void shuffle(Card *cards,int number_of_cards,FILE *fp){
    char *colr[]={"Spades","Hearts","Diamonds","Clubs"};
    char *numb[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    printf("Shuffle cards...\n");
    fprintf(fp,"Shuffle cards...\n");
    for(int i=0;i<number_of_cards;i++){
        int j = rand()%number_of_cards;//shuffle the cards
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;//shuffle the cards
    }
    printf("---------Shuffled cards successfully!!!!!----------\n");//print the shuffled cards
    fprintf(fp,"---------Shuffled cards successfully!!!!!----------\n");
    printf("Shuffled result:\n");
    fprintf(fp,"Shuffled result:\n");
    for (int k = 0; k < number_of_cards; k++) {
        fprintf(fp,"%s %s\n",colr[cards[k].color],numb[cards[k].number]);
    }
    
}



