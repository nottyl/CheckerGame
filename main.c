#include <stdio.h>
#include "checker.h"

int main(){
    int playerTurn = 1;
    checkerInitialize();
    checkerDisplay();
    while(winning!=1){
        playerTurn = checkerGame(playerTurn);
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
