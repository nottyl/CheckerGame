# CheckerGame

Made with C.   
This is an assignment for my Computer Programming class.

## How to Play

1. Play it as normal Chinese Checkers, you'll have to move all your marbles to the opposite side of the star to win.

2. This game is designed for **3 players**. Yellow starts first, then green, and red.
3. When a player takes a turn, they may move **one marble**. The marble can be moved to an adjacent open space or may jump over other marbles that are right next to the marble.
4. You can only jump over **one** marble each move.
5. The input (the marble you want to move, the destination) will have to be entered in coordinates in the format of x,y. Please check the reference screenshot below:
![Screenshot 2022-12-11 at 21 54 51](https://user-images.githubusercontent.com/71718049/206907793-cfdb35a0-c3ef-4ecc-8522-ca83ec7e318a.png)

## JetBrain IDE Users
You can **fork this project** then open it via CLion.   

## Known Issues
- The program crashes when input is not numerical values. (Fixed in the latest version)
- The program needs some tidying up and fix the duplicate `From:` display when detected non-numerical values
