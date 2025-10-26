#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "functions.h"
#include <string.h>

char * get_file(FILE * fp)
{
    char * content;
    char buffer[10];

    content = malloc(sizeof(char));
    content[0] = '\0';

    while(fgets(buffer, 10, fp) != NULL)
    {
        content = realloc(content, (strlen(buffer) * sizeof(char)) + strlen(content) * sizeof(char));
        content = strcat(content, buffer);
    }

    return content;
}

int main()
{
    char board[10][11];
    srand(time(NULL));
    char *playerName = malloc(sizeof(char));
    char goal;
    char player;
    char box;

    // intro

    system("clear");
    printf("\n\t\t\tWelcome to SOKOBAN!\n\n");
    sleep(1);
    printf("Enter your name, adventurer...\n");
    scanf("%s", playerName);
    printf("\nVery well, '%s'...\n", playerName);
    sleep(1);
    printf("Let's see what you're capable of.\n");
    sleep(2);
    system("clear");

    createBoard(board);

    int goalR, goalC;
    setBox(board);
    setGoal(board, &goalR, &goalC);
    int pRow, pColumn;
    playerSpawn(board, &pRow, &pColumn);

    
    
    showBoard(board);
    printf("\nEnter Z or W to go up, Q or A to go left, S to go down, and D to go right.\n");
    char move;
    int gameStatus = 0;
        
    do
    {
       scanf("%c", &move);
        if((move == 'z' || move == 'w') && board[pRow - 1][pColumn] != '#')
        {
            if(board[pRow - 1][pColumn] == 'X' && board[pRow - 2][pColumn] != '#')
            {
                board[pRow - 2][pColumn] = 'X';
                board[pRow][pColumn] = ' ';
                board[pRow - 1][pColumn] = 'o';
                pRow--;  
            }
            else if(board[pRow - 1][pColumn] == 'X' && board[pRow - 2][pColumn] == '#')
            {
                
            }
            else
            {
                board[pRow][pColumn] = ' ';
                board[pRow - 1][pColumn] = 'o';
                pRow--;   
            }
            
             
        }
        else if((move == 'q' || move == 'a') && board[pRow][pColumn - 1] != '#')
        {
            if(board[pRow][pColumn - 1] == 'X' && board[pRow][pColumn - 2] != '#')
            {
                board[pRow][pColumn - 2] = 'X';
                board[pRow][pColumn] = ' ';
                board[pRow][pColumn - 1] = 'o';
                pColumn--;
            }
            else if(board[pRow][pColumn - 1] == 'X' && board[pRow][pColumn - 2] == '#')
            {
                
            }
            else
            {
                board[pRow][pColumn] = ' ';
                board[pRow][pColumn - 1] = 'o';
                pColumn--;   
            }
        }
        else if(move == 's' && board[pRow + 1][pColumn] != '#')
        {
            if(board[pRow + 1][pColumn] == 'X' && board[pRow + 2][pColumn] != '#')
            {
                board[pRow + 2][pColumn] = 'X';
                board[pRow][pColumn] = ' ';
                board[pRow + 1][pColumn] = 'o';
                pRow++;  
            }
            else if(board[pRow + 1][pColumn] == 'X' && board[pRow + 2][pColumn] == '#')
            {
                
            }
            else
            {
                board[pRow][pColumn] = ' ';
                board[pRow + 1][pColumn] = 'o';
                pRow++;   
            }
        }
        else if(move == 'd' && board[pRow][pColumn + 1] != '#')
        {
            if(board[pRow][pColumn + 1] == 'X' && board[pRow][pColumn + 2] != '#')
            {
                board[pRow][pColumn + 2] = 'X';
                board[pRow][pColumn] = ' ';
                board[pRow][pColumn + 1] = 'o';
                pColumn++;
            }
            else if(board[pRow][pColumn + 1] == 'X' && board[pRow][pColumn + 2] == '#')
            {
                
            }
            else
            {
                board[pRow][pColumn] = ' ';
                board[pRow][pColumn + 1] = 'o';
                pColumn++;   
            }
        }

        if(board[goalR][goalC] == ' ')
        {
            board[goalR][goalC] = '.';
        }
        system("clear");
        showBoard(board);
        if(board[goalR][goalC] == 'X')
        {
            gameStatus = 1;
        }
        else
        {
            gameStatus = winloss(board);
        }
        
            
    } while (gameStatus == 0); // tant qu'aucune condition de fin n'a été remplie
        
    int message;
    message = rand() % 5;

    if(gameStatus == 1) // victoire
    {
        if(message == 0) // t'as trop dead ça
        {
            printf("quelle performance goatesque\n"); 
        }
        else if(message == 1)
        {
            printf("spectaculaire, renversant (à lire avec un accent québécois)\n");
        }
        else if(message == 2)
        {
            printf("c'est fou ça\n");
        }
        else if(message == 3)
        {
            printf("that's crazy bro\n");
        }
        else
        {
            printf("ben tabarnak sacré jeu\n");
        }
    }
    else // défaite
    {
         // self-explanatory
        if(message == 0) // t'as trop dead ça
        {
            printf("booooo loser :p blehhhh\n");
        }
        else if(message == 1)
        {
            printf("ohhh l'erreur du joueur français\n");
        }
        else if(message == 2)
        {
            printf("L bozo\n");
        }
        else if(message == 3)
        {
            printf("let me play the world's smallest violin\n");
        }
        else
        {
            printf("aw man, try again\n");
        }
    }

    FILE *fp = fopen("end.txt", "w+");

    if (fp == NULL)
    {
        printf("Failed to save the game board\n");
        return EXIT_FAILURE;
    }

    fprintf(fp, "Partie de %s\n\n", playerName);

    for(int i = 0; i < 10; i++)
    {
        fprintf(fp, "%s\n", board[i]);
    }

    fclose(fp);

    free(playerName);
    exit(0);
}