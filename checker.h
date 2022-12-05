#pragma once

extern int winning;
extern int board[17][25];
extern int boardNum[17];

void checkerInitialize();

void checkerDisplay();

int checkerWinning(int);

int checkerGame(int);