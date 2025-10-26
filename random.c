#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "functions.h"
#include <string.h>

void setGoal(char board[10][11], int *goalR, int *goalC)
{
    srand(time(NULL));
    int goalRow, goalColumn;

    do 
    {
        goalRow = rand() % 10;
        goalColumn = rand() % 10;
    } 
    while (board[goalRow][goalColumn] != ' ');
    board[goalRow][goalColumn] = '.';

    *goalR = goalRow;
    *goalC = goalColumn;
}

void playerSpawn(char board[10][11],  int *pRow, int *pColumn)
{
    srand(time(NULL));
    int r, c;

    do 
    {
        r = rand() % 10;
        c = rand() % 10;
    } 
    while (board[r][c] != ' ');
    board[r][c] = 'o';

    *pRow = r;
    *pColumn = c;
}

void setBox(char board[10][11])
{
    int bRow, bColumn;

    do 
    {
        bRow = rand() % 10;
        bColumn = rand() % 10;
    } 
    while (
        board[bRow][bColumn] != ' ' ||
        // 4 prochaines lignes : chatgpt (pour que la boite ne soit pas contre un mur)
        (bRow > 0     && board[bRow - 1][bColumn] == '#') || 
        (bRow < 9     && board[bRow + 1][bColumn] == '#') ||
        (bColumn > 0  && board[bRow][bColumn - 1] == '#') ||
        (bColumn < 9  && board[bRow][bColumn + 1] == '#')
    );

    board[bRow][bColumn] = 'X';
}