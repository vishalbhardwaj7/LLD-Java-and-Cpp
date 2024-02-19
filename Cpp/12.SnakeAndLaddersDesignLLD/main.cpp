#include <bits/stdc++.h>
using namespace std;

// objects identification
// dice -- can be n number dice 
// player -- player has to roll the dice
// cell -- has a just object if it is a ladder or a snake
// board .. should be a 2d array or vector of cells

class Jump{
    int head,tail;
};

class Cell{
    Jump *jump;// it is null initially
};

class Dice{
    int diceCount;
    int min=1,max=2;

    int rollDice(){
        int x=0;
        for(int i=0;i<diceCount;i++){
            // find a random between min and max and add to x
        }
        return x;
    }
};

class Board{
    vector<vector<Cell*>> *board;

    Board(int size){
        // initialize board with size x
        // add cells to all board
        // add snakes and ladders
    }

    void addSnakes(int snakes){
        while(snakes--){
            int snakeHead=random(1,board.size()*board.size()-1);// get a no. between 1 and 100
            int snakeTail = // same logic
            // head should > greater than tail
            if(head<tail)continue;

            // else
            // maka a jump
            Jump jump=(head,tail);

            //make a function to get cell
            getCell(pos).jump=jmup;///insert the jump there
        }
    }

    void addLadders(int number){
        //same logic but just head < tail is ok
    }

    Cell getCell(int pos){ // gwet pos from snakeHead in case of snake else get pos from ladderTail in case of ladder
        row=pos/size;
        col=pos%size;
        return board[row][col];
    }
};

class Player{
    //name and id
    string name;
    int currPostion;
};

class Game{
    deque<Player*> dq;
    Board *board;
    Dice *dice;

    Player *winner;

    // initialize players
    void addPlayess(){
        Player p1=  new Player("p1",0);//
        Player p2=  new Player("p1",0);//
    }

    void initializeGame(){
        // add players in deque
        // make a new board
        // make a new dice with dicecount 1

    }

    void startGame(){
        while(winner!=NULL){
            // get player turn
            // remove back from queu
            // 
            // roll dcie

            // int get new pos
            newPos= diceNumber+currentrPlauer.position;

            // add this to player current posiytiob
            // if (>=100)return wiinner

            // else add player to player list
        }
    }

    // logic to get new pos
    int jumpCheck(position){
        //check if this position has a jump
        // get row and col by modding thew posdion
        // if(cell[row][col].jump!=NULL){
            return position + cell[row][col].end;//new pos
        }
        return pos;/// if no jump is there 
    }
};
// 
main(){
    // make a game
    // game.startGamew()
} 