#include "initialize.h"
#include "game_mode.h"
#include "game_end.h"
#include "game_start.h"
#include "game_process.h"
#include "initialize_player.h"
#include "card_about.h"
void automatic(int n,int c,int d,int r,FILE *fp){
    int* score = (int*)calloc((size_t)n,sizeof(int));
    if (score == NULL) {printf("malloc failed\n"); exit(1);}//initialize the total score
    int round = r;
    while(r>0){
        Card cards[10*NUM_OF_CARDS],card_now;//initialize the cards
        char *colr[]={"Spades","Hearts","Diamonds","Clubs"};//initialize the color and number
        char *numb[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};//initialize the color and number
        Deck_Of_Cards *deck = init_deck(d);Deck_Of_Cards *used_card = init_deck(0);
        Player *head = initialize(n,c);//initialize the player list
        printf("------Round %d starts------\n",round-r+1);fprintf(fp,"------Round %d starts------\n",round-r+1);
        initialize_cards(cards,d);sort_card(cards,d*NUM_OF_CARDS);//sort the cards
        shuffle(cards,d*NUM_OF_CARDS,fp);//shuffle the cards  
        for (int i = 0;i<d*NUM_OF_CARDS;i++){
            printf("%s %s\n",colr[cards[i].color],numb[cards[i].number]);
        }        //print the shuffled cards
        memcpy(deck->card, cards, (size_t)d *(size_t) NUM_OF_CARDS * sizeof(cards[0]));//copy the shuffled cards to the deck
        deal_cards(head,deck,c,n,fp);//deal the cards to the players
        Player *player_card = head;
        for (int i = 0; i < n; i++) {
            printf("Player %d: ",i+1);fprintf(fp,"Player %d: ",i+1);
            for (int j = 0; j < c; j++) {
                printf("%s %s  ",colr[player_card->card[j].color],numb[player_card->card[j].number]);
                fprintf(fp,"%s %s  ",colr[player_card->card[j].color],numb[player_card->card[j].number]);
            }//print the cards of each player
            printf("\n");fprintf(fp,"\n");
            player_card = player_card->next;
        }
        int number_order = 0;//the order of the player
        number_order = decide_player(head,n,fp);//decide the first player
        printf("The game will start with Player %d\n",number_order + 1);fprintf(fp,"The game will start with Player %d\n",number_order + 1);
        Player *player_now = head;
        for (int i = 0;i<number_order;i++){player_now = player_now->next;}
        decide_card(deck,used_card,&card_now,fp);//just decide the color and number of the card.
        printf("\n --- Game start --- \n");fprintf(fp,"\n --- Game start --- \n");  
        int isattack = 0; int isskip = 0; int draw_cards = 0; int direction = 1;//initialize the special cards
        while (1){
            int flag = 0;int index = 0;//flag is to judge whether the player can play the card
            printf("Player %d has these cards: \n", player_now->order);fprintf(fp,"Player %d has these cards: \n", player_now->order);
            for (int i = 0; i < player_now->count; i++) {
                fprintf(fp,"%s %s  ", colr[player_now->card[i].color], numb[player_now->card[i].number]);fprintf(fp,"\n");
                printf("%s %s  ", colr[player_now->card[i].color], numb[player_now->card[i].number]); printf("\n");
            }
            for (int i = 0;i< player_now->count;i++){
                if (can_playcard(player_now,card_now.number,card_now.color,isattack,i) == 1){//judge whether the player can play the card
                    flag = 1;index = i;break;//index is the order of the card, which is used to play the card
                }
            }
            if (flag == 1){
                play_card(player_now,used_card,index+1,fp);//play the card
                card_now = used_card->card[used_card->count-1];//update the card_now
                special_card(&direction,&isattack,&isskip,&draw_cards,&card_now);//update the special cards
                if (player_now->count == 0){//if the player has no card, the round ends
                    printf("Player %d wins this round!\n",player_now->order);fprintf(fp,"Player %d wins this round!\n",player_now->order);             
                    for (int i = 0;i< n;i++){
                        player_now -> score -= player_now->count;
                        score[player_now->order-1] += player_now->score;//update the total score
                        printf("Player %d: %d\n",player_now->order,player_now->score);fprintf(fp,"Player %d: %d\n",player_now->order,player_now->score);
                        printf("Player %d total: %d\n",player_now->order,score[player_now->order-1]);fprintf(fp,"Player %d total: %d\n",player_now->order,score[player_now->order-1]);
                        player_now = player_now->next;
                    }
                    printf("------Round %d ends!------\n",round-r+1);
                    r--;break;
                }
            }else{
                if (deck->count <= 3){
                    printf("Stock pile exhausted. Shuffling the discard pile and restore the stock pile\n");
                    deck -> card = (Card*)malloc(sizeof(Card)*((size_t)used_card->count+(size_t)deck->count+1));//restore the deck
                    if (deck->card == NULL){printf("malloc failed\n");exit(1);}
                    for (int i = 0;i< used_card->count;i++){deck->card[i] = used_card->card[i];}//copy the used_card to the deck
                    for (int i = used_card->count;i<used_card->count+deck->count;i++){deck->card[i] = deck->card[i-used_card->count];}//copy the deck to the deck
                    deck->count = used_card->count+deck->count;//update the deck count
                    used_card->count = 0;//update the used_card count
                    shuffle(deck->card,deck->count,fp);//shuffle the deck
                    draw_card(player_now,deck,fp);//draw the card
                    for (int i = 0;i<draw_cards;i++){draw_card(player_now,deck,fp);}//draw the card needed
                    card_now = used_card->card[used_card->count-1];//update the card_now
                    isattack = 0; isskip = 0; draw_cards = 0;//update the special cards
                }else{
                    draw_card(player_now,deck,fp);
                    for (int i = 0;i<draw_cards;i++){draw_card(player_now,deck,fp);}
                    card_now = used_card->card[used_card->count-1];
                    isattack = 0;isskip =0; draw_cards = 0;
                }
            }
            change_player(&player_now,direction,isskip);//change the player
        }
        free(deck->card);free(deck);free(used_card->card);free(used_card);free_playerlist(&head);
    }   
    printf("------Game ends!------\n");fprintf(fp,"------Game ends!------\n");
    free(score);
}




