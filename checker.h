#pragma once

extern int winning;
extern int board[17][25];
extern int boardNum[17];

void checkerInitialize();

void checkerDisplay();

int checkerWinning(int);

void inputValidity(int x, int y, int player, int io);

int checkerGame(int);