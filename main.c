//Made by @nottyl
#include <stdio.h>
#include "checker.h"

int main(){
    int playerTurn = 1;
    printf("\e[1;1H\e[2J");
    checkerInitialize();
    checkerDisplay();
    while(winning!=1){
        playerTurn = checkerGame(playerTurn);
        printf("\e[1;1H\e[2J");
        checkerDisplay();
    }
    printf("The Winner is ");
    if(playerTurn%3==1){
        printf("Yellow");
    }
    else if(playerTurn%3==2){
        printf("Green");
    }
    else{
        printf("Red");
    }
    return 0;
}
