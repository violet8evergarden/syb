#include"initialize.h"
#include"game_process.h"
int can_playcard(Player *player,int number,int color,int isattack,int i){
    int flag = 0;
    if (isattack == 0){//if the card is not attack card
        if (player ->card[i].number == number || player ->card[i].color == color){
            flag = 1;//if the card is not attack card, it can be played if the number or color is the same
        }
        else
        {
            flag = 0;
        }
    }
    else if (isattack == 1)//if the card is attack card
    {
        if (player ->card[i].number == number){//if the card is attack card(2 or)
            flag = 1;
        }
        else if (player ->card[i].number == 5)// it is a defend card
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        
    }
    return flag;//if flag = 1, the card can be played, if flag = 0, the card can not be played
}


