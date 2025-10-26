#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "functions.h"
#include <string.h>

void createBoard(char board[10][11])
{
    strcpy(board[0], "##########");
    strcpy(board[9], "##########");

    for(int i = 1; i < 9; i++) 
    {
        strcpy(board[i], "#        #");
    }
}

void showBoard(char board[10][11])
{
    for(int i = 0; i < 10; i++)
    {
        printf("%s\n", board[i]);
    }
}

int winloss(char board[10][11])
{    
     int boxRow = -1, boxCol = -1;

    for (int r = 0; r < 10; r++) // morceau de code de chatgpt pour trouver la boite sur le tableau
    {
        for (int c = 0; c < 10; c++)
        {
            if (board[r][c] == 'X')
            {
                boxRow = r;
                boxCol = c;
                break;
            }
        }
        if (boxRow != -1) break;
    }

     int goalRow = -1, goalCol = -1;



    int up    = (boxRow > 0 && board[boxRow - 1][boxCol] == '#'); // chatgpt - vérifie si la boite touche un mur
    int down  = (boxRow < 9 && board[boxRow + 1][boxCol] == '#');
    int left  = (boxCol > 0 && board[boxRow][boxCol - 1] == '#');
    int right = (boxCol < 9 && board[boxRow][boxCol + 1] == '#');

        if ((up && left) || (up && right) || (down && left) || (down && right)) // vérifie si elle en touche 2
            return 2; // game over
    
    return 0; // la partie n'est pas finie
}