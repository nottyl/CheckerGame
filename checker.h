#pragma once

extern int winning;
extern int board[17][25];
extern int boardNum[17];
extern int inputX, inputY, outputX, outputY;

void checkerInitialize();

void checkerDisplay();

int checkerWinning(int);

int checkerValidity(int, int, int, int);

void checkerMove(int, int, int);

int checkerGame(int);