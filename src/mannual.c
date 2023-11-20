#include "initialize.h"
#include "game_mode.h"
#include "game_end.h"
#include "game_start.h"
#include "game_process.h"
#include "initialize_player.h"
#include "card_about.h"
void mannual(int n,int c,int d,int r,FILE *fp){
    printf("\n --- Game start --- \n");fprintf(fp,"\n --- Game start --- \n");
    int* score = (int*)calloc((size_t)n,sizeof(int));
    if (score == NULL){printf("malloc failed\n");exit(1); }
    int round = r;
    while(r>0){
        Card cards[10*NUM_OF_CARDS],card_now;//initialize the cards
        char *colr[]={"Spades","Hearts","Diamonds","Clubs"};
        char *numb[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
        Deck_Of_Cards *deck = init_deck(d);Deck_Of_Cards *used_card = init_deck(0);
        Player *head = initialize(n,c);
        printf("------Round %d starts------\n",round-r+1);
        initialize_cards(cards,d);
        sort_card(cards,d*NUM_OF_CARDS);//sort the cards
        shuffle(cards,d*NUM_OF_CARDS,fp);//shuffle the cards          
        memcpy(deck->card, cards, (size_t)d * (size_t)NUM_OF_CARDS * sizeof(cards[0]));
        deal_cards(head,deck,c,n,fp);
        Player *player_card = head;
        for (int i = 0; i < n; i++) {
            printf("Player %d: ",i+1);fprintf(fp,"Player %d: ",i+1);
            for (int j = 0; j < c; j++) {
                printf("%s %s  ",colr[player_card->card[j].color],numb[player_card->card[j].number]); fprintf(fp,"%s %s  ",colr[player_card->card[j].color],numb[player_card->card[j].number]);
            }
            printf("\n");fprintf(fp,"\n");player_card = player_card->next;
        }
        int number_order = decide_player(head,n,fp);//decide the first player
        printf("The game will start with Player %d\n",number_order + 1);fprintf(fp,"The game will start with Player %d\n",number_order + 1);
        Player *player_now = head;
        for (int i = 0;i<number_order;i++){player_now = player_now->next;}//change the head to the first player
        decide_card(deck,used_card,&card_now,fp);//just decide the color and number of the card.
        printcard(card_now.color,card_now.number,fp);//show the card
        int isattack = 0; int isskip = 0; int draw_cards = 0; int direction = 1;
        while (1){    
            sort_card(player_now->card,player_now->count);
            printf("You has these cards: \n");fprintf(fp,"You has these cards: \n");
            for (int i = 0; i < player_now->count; i++) {
                printf("%s %s  ", colr[player_now->card[i].color], numb[player_now->card[i].number]);fprintf(fp,"%s %s  ", colr[player_now->card[i].color], numb[player_now->card[i].number]);
            }
            int flag = 0;//flag is to judge whether the player can play the card
            for (int i = 0;i< player_now->count;i++){
                if (can_playcard(player_now,card_now.number,card_now.color,isattack,i) == 1){  flag = 1;break; }
            }
            if (flag == 1){
                if (getchoice(fp) == 1){
                    printf("You choose to play which card\n");fprintf(fp,"You choose to play which card\n");
                    int choose = make_choice(player_now,card_now,isattack,fp);
                    play_card(player_now,used_card,choose,fp);
                    card_now = used_card->card[used_card->count-1];
                    special_card(&direction,&isattack,&isskip,&draw_cards,&card_now);
                    if (player_now->count == 0){
                        printf("Player %d wins this ro nd!\n",player_now->order);fprintf(fp,"Player %d wins this round!\n",player_now->order);               
                        for (int i = 0;i< n;i++){
                            player_now -> score -= player_now->count;score[player_now->order-1] += player_now->score;
                            printf("Player %d: %d\n",player_now->order,player_now->score);fprintf(fp,"Player %d: %d\n",player_now->order,player_now->score);
                            player_now = player_now->next;
                        }
                        printf("------Round %d ends!------\n",round-r+1);fprintf(fp,"------Round %d ends!------\n",round-r+1);
                        r--;break;
                    }
                }else {
                    printf("You choose to draw a card\n");fprintf(fp,"You choose to draw a card\n");
                    draw_card(player_now,deck,fp);
                    for (int i = 0;i<draw_cards;i++) { draw_card(player_now,deck,fp); }
                    card_now = used_card->card[used_card->count-1];
                    isattack = 0; isskip = 0; draw_cards = 0;
                }
            }else{
                if (deck->count <= 3){
                    printf("You have to draw card\n");fprintf(fp,"You have to draw card\n");
                    printf("Stock pile exhausted. Shuffling the discard pile and restore the stock pile\n");fprintf(fp,"Stock pile exhausted. Shuffling the discard pile and restore the stock pile\n");
                    deck -> card = (Card*)malloc(sizeof(Card)*((size_t)used_card->count+(size_t)deck->count+1));
                    if (deck->card == NULL){printf("malloc failed\n");exit(1);}
                    for (int i = 0;i< used_card->count;i++) { deck->card[i] = used_card->card[i]; }
                    for (int i = used_card->count;i<used_card->count+deck->count;i++) { deck->card[i] = deck->card[i-used_card->count]; }
                    deck->count = used_card->count+deck->count; used_card->count = 0;
                    shuffle(deck->card,deck->count,fp); draw_card(player_now,deck,fp);//
                    for (int i = 0;i<draw_cards;i++) { draw_card(player_now,deck,fp); }
                    isattack = 0; isskip = 0; draw_cards = 0;
                }else{
                    printf("You have to draw cards\n");fprintf(fp,"You have to draw cards\n");
                    draw_card(player_now,deck,fp);
                    for (int i = 0;i<draw_cards;i++)  {  draw_card(player_now,deck,fp); }
                    isattack = 0;isskip =0; draw_cards = 0;
                }
            }
            change_player(&player_now,direction,isskip);cleanscreen(fp);
            printf("The card now is: \n");fprintf(fp,"The card now is: \n");
            printcard(card_now.color,card_now.number,fp);
        }
        free(deck->card);free(deck);free(used_card->card);free(used_card);free_playerlist(&head);
    }   
    printf("------Game ends!------\n");fprintf(fp,"------Game ends!------\n");
    printf("The final score is:\n");fprintf(fp,"The final score is:\n");
    for (int i = 0;i<n;i++){
        printf("Player %d: %d\n",i+1,score[i]);fprintf(fp,"Player %d: %d\n",i+1,score[i]);
    }
    free(score);
}



