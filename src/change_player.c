#include "initialize.h"
#include "game_end.h"
void change_player(Player **player_now, int direction, int isskip) {
    if (direction == 0) {//clockwise
        if (isskip == 1) {
            *player_now = (*player_now)->next->next;//if the card is skip card, the player will be skipped
        } else {
            *player_now = (*player_now)->next;//if the card is not skip card, the player will not be skipped
        }
    } else {//anticlockwise
        if (isskip == 1) {
            *player_now = (*player_now)->prev->prev;//if the card is skip card, the player will be skipped
        } else {
            *player_now = (*player_now)->prev;//if the card is not skip card, the player will not be skipped
        }
    }

}
