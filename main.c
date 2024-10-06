#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define player 'X'
#define robot 'O'

void displayBord(char simplchart[9]);
void robotMove(char simplchart[9]);
void playerMove(char simplichart[9]);
int checkWin(char simplchart[9]);

void displayBord(char simplchart[9])
/*
On print la structure du tableau qui apparaitera pendant la partie
*/
{
        printf("\n");
        printf(" %c | %c | %c \n", simplchart[0], simplchart[1], simplchart[2]);
        printf("-----------\n");
        printf(" %c | %c | %c \n", simplchart[3], simplchart[4], simplchart[5]);
        printf("-----------\n");
        printf(" %c | %c | %c \n", simplchart[6], simplchart[7], simplchart[8]);
        printf("\n");
}

int checkWin(char simplchart[9])
/*
Ici le programme vérifier si l'un des joueurs à gagner
*/
{
    for(int i = 0; i < 9; i += 3)
{
    if(simplchart[i] == simplchart[i+1] && simplchart[i+1] && simplchart[i+2] && simplchart[i] != ' ')
{
    return(simplchart[i] == player) ? 1 : -1;
    }
    }

    for(int i = 0; i < 3; i++)
{
    if(simplchart[i] == simplchart[i+3] && simplchart[i+3] == simplchart[i+6] && simplchart[i] != ' ')   
{ 
    return(simplchart[i] == player) ? 1 : -1;
    }
    }
    if(simplchart[0] == simplchart[4] && simplchart[4] == simplchart[8] && simplchart[0] != ' ')
{
    return(simplchart[0] == player) ? 1 : -1;
    }
    if(simplchart[2] == simplchart[4] && simplchart[4] == simplchart[6] && simplchart[2] != ' ')
{
    return(simplchart[2] == player) ? 1 : -1;
    }
    return 0;
}

void playerMove(char simplchart[9])
/*
Le joueur doit sélectionner la case ou il souhaite jouer,
et si la case est déjà prise alors on lui demande de réessayer
*/
{
    int move;
        printf("Choisissez où jouer (1-9) : ");
    while(1)
{
        scanf("%d", &move);
    if(move >= 1 && move <= 9 && simplchart[move-1] == ' ')
{
        simplchart[move-1] = player;
    break;
    }
    else
{
        printf("Mouvement invalide veuillez réessayer : ");
    }
    }
}

void robotMove(char simplchart[9])
/*
Au tour du robot j'ai fait en sorte qu'il joue aléatoirement,
mais si le milieu est disponible il devra le prioriser pour le rendre plus compliquer à battre
*/
{
        printf("Au tour du robot :\n");
    if(simplchart[4] == ' ')
{
        simplchart[4] = robot;
    }
    else
{
    int move;
    while (1)
{
        move = rand() % 9;
    if(simplchart[move] == ' ')
{
        simplchart[move] = robot;
    break;
    }
    }
    }
}

int main()
/*
Boucle principale qui permet au joueur et au robot de jouer à tour de rôle
tout au long du déroulement de la partie et 
si quelqu'un a gagner la boucle le vérifie aussi en utilisant la variable chekWin,
pour finir elle fera un print du résultat du match
*/
{
    char simplchart[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' '};

    int winner = 0;
    int moves = 0;

        srand(time(0));

        printf("Début d'une partie de tic tac toe :\n");

    while(winner == 0 && moves < 9)
{
        displayBord(simplchart);
        
        playerMove(simplchart);
        moves++;
    if((winner = checkWin(simplchart)) != 0 || moves == 9)
    break;
        
        robotMove(simplchart);
        moves++;
    if((winner = checkWin(simplchart)) != 0 || moves ==9)
    break;
    }

        displayBord(simplchart);

    if(winner == 1)
{
        printf("C'est gagné!\n");
    }
    else if(winner == -1)
{
        printf("C'est perdu!\n");
    }
    else
{
        printf("Match Nul!\n");
    }

    return 0;
}