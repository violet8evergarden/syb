#include "initialize.h"
#include "initialize_player.h"
Player *initialize_playerlist(int number_perplayer){//initialize the player list's head
    Player *head = (Player*)malloc(sizeof(Player));
    if (head == NULL){
        printf("malloc error\n");
        exit(1);
    }
    head ->count = 0;//initialize the head of the player list
    head -> score = 0;//initialize the head of the player list
    head -> order = 1;//the first player
    head -> card = (Card*)malloc(sizeof(Card)*(size_t)(number_perplayer));//initialize the head of the player list
    if (head -> card == NULL){
        printf("malloc error\n");
        exit(1);
    }
    head -> next = head -> prev = head;
    
    return head;
}
void insertlist(Player *head,int number_perplayer,int i){//insert the player to the player list
    Player *newnode = (Player*)malloc(sizeof(Player));
    if (newnode == NULL){
        printf("malloc error\n");
        exit(1);
    }
    newnode -> count = 0;
    newnode -> score = 0;
    newnode -> order = i;//the order of the player
    newnode -> card = (Card*)malloc(sizeof(Card)*(size_t)(number_perplayer));
    if (newnode -> card == NULL){
        printf("malloc error\n");
        exit(1);
    } 
    newnode->next = head->next;
    newnode->prev = head;
    head->next->prev = newnode;
    head->next = newnode;
}
Player *initialize(int n,int number_perplayer){
    Player *head = initialize_playerlist(number_perplayer);
    for (int i = 0;i < n-1;i++){
        insertlist(head,number_perplayer,n-i);//insert the player to the player list
    }
    return head;

}
void free_playerlist(Player **head) {
    if (*head == NULL) {
        return;
    }
    // Break the circularity
    Player *last = (*head)->prev; 
    last->next = NULL;
    Player *temp = *head;
    while (temp != NULL) {
        Player *next = temp->next;
        free(temp->card);//free the card
        temp->card = NULL;
        // Free the node
        free(temp);
        // Move to the next node
        temp = next;
    }
    // Avoid dangling pointers
    *head = NULL;
}



