
#include"initialize.h"
#include"game_end.h"
void printcard(int a, int b,FILE *fp) {
    char *nu[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    printf("--------------\n"); fprintf(fp,"--------------\n");
    if (b != 8) {// Print the ASCII art for the suit
        printf("|%s           |\n", nu[b]);
        fprintf(fp,"|%s           |\n", nu[b]);
    } else {
        printf("|%s          |\n", nu[b]);
        fprintf(fp,"|%s          |\n", nu[b]);
    }
    switch (a) {// Print the ASCII art for the suit
        case 0:
        printf("|     /\\     |\n"); fprintf(fp,"|     /\\     |\n");
        printf("|    /  \\    |\n"); fprintf(fp,"|    /  \\    |\n");
        printf("|  /      \\  |\n");  fprintf(fp,"|  /      \\  |\n");
        printf("|  \\_/||\\_/  |\n"); fprintf(fp,"|  \\_/||\\_/  |\n");
        printf("|     ||     |\n");  fprintf(fp,"|     ||     |\n");
            break;
        case 1:
            printf("|   __  __   |\n");  fprintf(fp,"|   __  __   |\n");
            printf("|  /  \\/  \\  |\n");  fprintf(fp,"|  /  \\/  \\  |\n");
            printf("|  \\      /  |\n");    fprintf(fp,"|  \\      /  |\n");
            printf("|    \\  /    |\n");  fprintf(fp,"|    \\  /    |\n");
            printf("|     \\/     |\n");  fprintf(fp,"|     \\/     |\n");
            break;
        case 2:
            printf("|            |\n"); fprintf(fp,"|            |\n"); 
            printf("|     /\\     |\n"); fprintf(fp,"|     /\\     |\n");
            printf("|    /  \\    |\n"); fprintf(fp,"|    /  \\    |\n");
            printf("|    \\  /    |\n");  fprintf(fp,"|    \\  /    |\n");
            printf("|     \\/     |\n");    fprintf(fp,"|     \\/     |\n");
            printf("|            |\n"); fprintf(fp,"|            |\n"); 
            break;
           
        case 3:
            printf("|      _     |\n"); fprintf(fp,"|      _     |\n"); 
            printf("|    _( )_   |\n");  fprintf(fp,"|    _( )_   |\n");
            printf("|   (     )  |\n"); fprintf(fp,"|   (     )  |\n");
            printf("|     /_\\    |\n");  fprintf(fp,"|     /_\\    |\n");
            printf("|            |\n"); fprintf(fp,"|            |\n"); 
            break;
    }
    if (b != 8) {// Print the ASCII art for the suit
        printf("|           %s|\n", nu[b]);
        fprintf(fp,"|           %s|\n", nu[b]);
    } else {//
        printf("|          %s|\n", nu[b]);
        fprintf(fp,"|          %s|\n", nu[b]);
    }
    printf("--------------\n");fprintf(fp,"--------------\n");
}




