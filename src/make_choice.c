#include"game_process.h"
#include"initialize.h"
int make_choice(Player *player_now, Card card_now, int isattack, FILE *fp) {
    int choose = 0;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choose);
        if (choose > player_now->count || choose < 1) {
            printf("Invalid input, please input again\n");
            fprintf(fp, "Invalid input, please input again\n");
        } else {
            int playability = can_playcard(player_now, card_now.number, card_now.color, isattack, choose - 1);
            if (playability == 0) {
                printf("You can't play this card\n");
                fprintf(fp, "You can't play this card\n");
            } else if (playability == 1) {
                break;
            } else {
                printf("Invalid input, please input again\n");
                fprintf(fp, "Invalid input, please input again\n");
            }
        }
    }
    return choose;
}
