#include "checker.h"
#include <stdio.h>

int winning = 0;
int inputX = 0, inputY = 0, outputX = 0, outputY = 0;
int board[17][25];
int boardNum[17] = {1, 2, 3, 4, 13, 12, 11, 10, 9,
                    10, 11, 12, 13, 4, 3, 2, 1};

void checkerInitialize(){
    int left[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                    5, 6, 7, 8, 0, 0, 0, 0};
    int right[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                     19, 18, 17, 16, 0, 0, 0, 0};

    //Initial: All blank
    for(int a = 0; a < 17; a++){
        for(int b = 0; b < 25; b++){
            board[a][b] = -1;
        }
    }

    //Print out the star shape
    for(int i = 0; i < 17; i++){
        //Left part of the star shape
        for(int j = 12; j <= 11 + boardNum[i]; j++){
            if(i % 2 == 0 || i == 0){
                if(j % 2 == 0){
                    board[i][j] = 0;
                }
                else{
                    board[i][j] = -1;
                }
            }
            else{
                if(j % 2 == 0){
                    board[i][j] = -1;
                }
                else{
                    board[i][j] = 0;
                }
            }
            //yellow
            if(i < 4){
                if(board[i][j] == 0){
                    board[i][j] = 3;
                }
            }
                //red
            else if(i > 8 && i < 13){
                for(int k = 24; k > right[i]; k--){
                    if(board[i][k] == 0){
                        board[i][k] = 1;
                    }
                }
            }
        }
        //Right part of the star shape
        for(int j = 12; j >= 13 - boardNum[i]; j--){
            if(i % 2 == 0 || i == 0){
                if(j % 2 == 0){
                    board[i][j] = 0;
                }
                else{
                    board[i][j] = -1;
                }
            }
            else{
                if(j % 2 == 0){
                    board[i][j] = -1;
                }
                else{
                    board[i][j] = 0;
                }
            }
            //yellow
            if(i < 4){
                if(board[i][j] == 0){
                    board[i][j] = 3;
                }
            }
                //green
            else if(i > 8 && i < 13){
                for(int k = 0; k < left[i]; k++){
                    if(board[i][k] == 0){
                        board[i][k] = 2;
                    }
                }
            }
        }
    }
}

void checkerDisplay(){
    //-1 = Gap, 0 = Space, 1 = Red, 2 = Green, 3 = Yellow
    for(int i = 0; i < 17; i++){
        for(int j = 0; j < 25; j++){
            if(board[i][j] == -1){
                printf(" ");
            }
            else if(board[i][j] == 0){
                printf("*");
            }
            else if(board[i][j] == 1){
                printf("\e[31m*\e[m");
            }
            else if(board[i][j] == 2){
                printf("\e[32m*\e[m");
            }
            else if(board[i][j] == 3){
                printf("\e[93m*\e[m");
            }
        }
        printf("\n");
    }
}

int checkerWinning(int input){
    if(input == 0){
        int a = 7;
        int count = 0;
        for(int i = 5; i < 9; i++){
                for(int k = 0; k < a; k++){
                    if(board[i][k] == 1){
                        count++;
                    }
                }
            a--;
        }
        if(count == 10){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(input == 1){
        int a = 25;
        int count = 0;
        for(int i = 13; i < 17; i++){
            for(int k = 0; k < a; k++){
                if(board[i][k] == 3){
                    count++;
                }
            }
            a--;
        }
        if(count == 10){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(input == 2){
        int a = 17;
        int count = 0;
        for(int i = 5; i < 9; i++){
            for(int k = 25; k > a; k--){
                if(board[i][k] == 2){
                    count++;
                }
            }
            a++;
        }
        if(count == 10){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int checkerValidity(int x, int y, int playerTurn, int io){
    if(playerTurn == 1){
        if(io == 0){
            y += 1;
            for(int i = 0; i < 25; i++){
                if(board[x][i] != -1){
                    y--;
                }
                if(y == 0){
                    y = i;
                    break;
                }
            }
            if(board[x][y] == 3){
                if(board[x][y+2]==0||board[x][y-2]==0||board[x+1][y-1]==0||board[x+1][y+1]==0||board[x-1][y+1]==0||board[x-1][y-1]==0){
                    inputX = x;
                    inputY = y;
                    return 0;
                }
                else if(board[x][y+4]==0 || board[x][y-4]==0 || board[x+2][y-1]==0 || board[x+2][y+1]==0 || board[x-2][y+1]==0 || board[x-2][y-1]==0){
                    inputX = x;
                    inputY = y;
                    return 0;
                }
                else{
                    printf("No moves can be made! Please enter again.\n");
                    return 1;
                }
            }
            else{
                printf("Invalid Input! Please enter again.\n");
                return 1;
            }
        }
        else if(io == 1){
            y += 1;
            for(int i = 0; i < 25; i++){
                if(board[x][i] != -1){
                    y--;
                }
                if(y == 0){
                    y = i;
                    break;
                }
            }
            if(board[x][y] == 0){
                if(x==inputX && (y==inputY+2 || y==inputY-2) ||
                   (x==inputX-1 || x==inputX+1) && (y==inputY-1 || y==inputY+1)){
                    outputY = y;
                    return 0;
                }
                else if((x==inputX+2 || x==inputX-2) && (y==inputY+2 || y==inputY-2) ||
                x==inputX && (y==inputY-4 || y==inputY+4)){
                    outputY = y;
                    return 0;
                }
                else{
                    printf("Invalid Input! Please enter again.\n");
                    return 1;
                }
            }
            else{
                printf("Invalid Input! Please enter again.\n");
                return 1;
            }
        }
    }
    else if(playerTurn == 2){
        if(io == 0){
            y += 1;
            for(int i = 0; i < 25; i++){
                if(board[x][i] != -1){
                    y--;
                }
                if(y == 0){
                    y = i;
                    break;
                }
            }
            if(board[x][y] == 2){
                if(board[x][y+2]==0||board[x][y-2]==0||board[x+1][y-1]==0||board[x+1][y+1]==0||board[x-1][y+1]==0||board[x-1][y-1]==0){
                    inputX = x;
                    inputY = y;
                    return 0;
                }
                else if(board[x][y+4]==0 || board[x][y-4]==0 || board[x+2][y-1]==0 || board[x+2][y+1]==0 || board[x-2][y+1]==0 || board[x-2][y-1]==0){
                    inputX = x;
                    inputY = y;
                    return 0;
                }
                else{
                    printf("No moves can be made! Please enter again.\n");
                    return 1;
                }
            }
            else{
                printf("Invalid Input! Please enter again.\n");
                return 1;
            }
        }
        else if(io == 1){
            y += 1;
            for(int i = 0; i < 25; i++){
                if(board[x][i] != -1){
                    y--;
                }
                if(y == 0){
                    y = i;
                    break;
                }
            }
            if(board[x][y] == 0){
                if(x==inputX && (y==inputY+2 || y==inputY-2) ||
                   (x==inputX-1 || x==inputX+1) && (y==inputY-1 || y==inputY+1)){
                    outputY = y;
                    return 0;
                }
                else if((x==inputX+2 || x==inputX-2) && (y==inputY+2 || y==inputY-2) ||
                        x==inputX && (y==inputY-4 || y==inputY+4)){
                    outputY = y;
                    return 0;
                }
                else{
                    printf("Invalid Input! Please enter again.\n");
                    return 1;
                }
            }
            else{
                printf("Invalid Input! Please enter again.\n");
                return 1;
            }
        }
    }
    else{
        if(io == 0){
            y += 1;
            for(int i = 0; i < 25; i++){
                if(board[x][i] != -1){
                    y--;
                }
                if(y == 0){
                    y = i;
                    break;
                }
            }
            if(board[x][y] == 1){
                if(board[x][y+2]==0||board[x][y-2]==0||board[x+1][y-1]==0||board[x+1][y+1]==0||board[x-1][y+1]==0||board[x-1][y-1]==0){
                    inputX = x;
                    inputY = y;
                    return 0;
                }
                else if(board[x][y+4]==0 || board[x][y-4]==0 || board[x+2][y-1]==0 || board[x+2][y+1]==0 || board[x-2][y+1]==0 || board[x-2][y-1]==0){
                    inputX = x;
                    inputY = y;
                    return 0;
                }
                else{
                    printf("No moves can be move! Please enter again.\n");
                    return 1;
                }
            }
            else{
                printf("Invalid Input! Please enter again.\n");
                return 1;
            }
        }
        else if(io == 1){
            y += 1;
            for(int i = 0; i < 25; i++){
                if(board[x][i] != -1){
                    y--;
                }
                if(y == 0){
                    y = i;
                    break;
                }
            }
            if(board[x][y] == 0){
                if(x==inputX && (y==inputY+2 || y==inputY-2) ||
                   (x==inputX-1 || x==inputX+1) && (y==inputY-1 || y==inputY+1)){
                    outputY = y;
                    return 0;
                }
                else if((x==inputX+2 || x==inputX-2) && (y==inputY+2 || y==inputY-2) ||
                        x==inputX && (y==inputY-4 || y==inputY+4)){
                    outputY = y;
                    return 0;
                }
                else{
                    printf("Invalid Input! Please enter again.\n");
                    return 1;
                }
            }
            else{
                printf("Invalid Input! Please enter again.\n");
                return 1;
            }
        }
    }
}

void checkerMove(int iX, int oX, int color){
    board[iX][inputY] = 0;
    board[oX][outputY] = color;
}

int checkerGame(int input){
    int playerTurn = input % 3;
    int iptX = 0, iptY = 0, optX = 0, optY = 0;

    switch(playerTurn){
        case 1:
            //Yellow's Turn
            printf("Yellow Player Turn:\n");
            printf("From: ");
            scanf("%d, %d", &iptX, &iptY);
            while(checkerValidity(iptX, iptY, 1, 0) != 0){
                printf("From: ");
                scanf("%d, %d", &iptX, &iptY);
            }
            printf("To: ");
            scanf("%d, %d", &optX, &optY);
            while(checkerValidity(optX, optY, 1, 1) != 0){
                printf("To: ");
                scanf("%d, %d", &optX, &optY);
            }
            checkerMove(iptX, optX, 3);
            break;
        case 2:
            //Green's Turn
            printf("Green Player Turn:\n");
            printf("From: ");
            scanf("%d, %d", &iptX, &iptY);
            while(checkerValidity(iptX, iptY, 2, 0) != 0){
                printf("From: ");
                scanf("%d, %d", &iptX, &iptY);
            }
            printf("To: ");
            scanf("%d, %d", &optX, &optY);
            while(checkerValidity(optX, optY, 2, 1) != 0){
                printf("To: ");
                scanf("%d, %d", &optX, &optY);
            }
            checkerMove(iptX, optX, 2);
            break;
        case 0:
            //Red's Turn
            printf("Red Player Turn:\n");
            printf("From: ");
            scanf("%d, %d", &iptX, &iptY);
            while(checkerValidity(iptX, iptY, 0, 0) != 0){
                printf("To: ");
                scanf("%d, %d", &optX, &optY);
            }
            printf("To: ");
            scanf("%d, %d", &optX, &optY);
            while(checkerValidity(optX, optY, 0, 1) != 0){
                printf("To: ");
                scanf("%d, %d", &optX, &optY);
            }
            checkerMove(iptX, optX, 1);
            break;
    }
    if(checkerWinning(playerTurn) == 1){
        winning = 1;
        return input;
    }
    else{
        input++;
        return input;
    }
}