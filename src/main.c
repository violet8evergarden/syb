#include "initialize.h"
#include "game_mode.h"
#include "game_end.h"
#include "game_start.h"
#include "game_process.h"
#include "initialize_player.h"
#include "card_about.h"
int main(int argc, char *argv[]){
    srand((unsigned)time(NULL));
    struct option longopts[] = {
        {"help",no_argument,NULL,'h'},
        {"initial cards",required_argument,NULL,'c'},
        {"number",required_argument,NULL,'n'},
        {"round",required_argument,NULL,'r'},
        {"auto", no_argument, NULL, 'a'},
        {"log", required_argument, 0, 'l'},
        {"deck", required_argument, 0, 'd'},
        {0,0,0,0}
    };      
    int option = 0;
    int n = 4;
    int r = 3;
    int c = 5;
    char *log = "onecard.log";
    int d = 2;
    FILE *fp = NULL;
    fp = fopen(log,"w");
    fprintf(fp,"########################\n");printf("########################\n");
    fprintf(fp,"#                      #\n"); printf("#                      #\n");
    fprintf(fp,"#  Welcome to One Card #\n"); printf("#  Welcome to One Card #\n");
    fprintf(fp,"#                      #\n"); printf("#                      #\n");
    fprintf(fp,"########################\n"); printf("########################\n");
    fprintf(fp,"\n"); printf("\n");
    fprintf(fp, "---- Initial setup ----\n"); printf("---- Initial setup ----\n");
    fprintf(fp,"The number of players is %d\n",n); printf("The number of players is %d\n",n);
    fprintf(fp,"The round of game is %d\n",r); printf("The round of game is %d\n",r);
    fprintf(fp,"The number of cards per player is %d\n",c); printf("The number of cards per player is %d\n",c);
    fprintf(fp,"The number of decks is %d\n",d); printf("The number of decks is %d\n",d);
    fprintf(fp,"\n");   printf("\n");
    while ((option = getopt_long(argc, argv, "hal:n:c:r:d:", longopts, NULL)) != -1) {
        switch (option) {  
            case 'h':// Handle the --help option
                printf("Usage: %s [OPTIONS]\n", argv[0]);
                printf("Options:\n");
                printf("  -h| --help       Display this help message\n");
                printf("  -n| --number     Set the number of players\n");
                printf("  -r| --round      Set the number of rounds\n");
                printf("  -c| --initial    Set the number of initial cards\n");
                printf("  -a| --auto       Enable auto play mode\n");
                printf("  -l| --log        Set the log file\n");
                printf("  -d| --deck       Set the number of decks\n");
                exit(EXIT_SUCCESS);
            case 'c':
                c = atoi(optarg);
                break;// Handle the --initial number of cards 
            case 'n':
                // Handle the --number of players option
                n = atoi(optarg);
                break;
            case 'd':
                d = atoi(optarg);
                break;// Handle the --deck option
            case 'a':
                automatic(n,c,d,r,fp);
                return 0;
                break;// Handle the --auto option
            case 'l':
                log = optarg;
                break;// Handle the --log option
            case 'r':
                r = atoi(optarg);
                break;
            case '?':
                // Handle unrecognized options
                printf("Try '%s --help' for more information.\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    mannual(n,c,d,r,fp);// Handle the manual mode
    fclose(fp);
}


