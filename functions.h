#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void createBoard(char board[10][11]);
void showBoard(char board[10][11]);
void setGoal(char board[10][11], int *goalR, int *goalC);
void playerSpawn(char board[10][11],  int *pRow, int *pColumn);
void setBox(char board[10][11]);
int winloss(char board[10][11]);
#endif