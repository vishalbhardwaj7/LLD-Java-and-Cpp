#include<bits/stdc++.h>
using namespace std;


// make a piece

enum Piece{
    X,
    O,
    N // N here means null pointor
};

class PlayingPiece{ // making this class so that in future any kind of new piece can be added
public:
    Piece piece;
    PlayingPiece():piece(N){}
    PlayingPiece(Piece piece){ // Piece &Piece does not work because enums are passed like value always 
        this->piece=piece;
    }

    void printPiece(){
        if(piece==X)cout<<"X";
        else cout<< "O";
    }
};

class XPiece: public PlayingPiece{
public:
    XPiece():PlayingPiece(X){}
};

class OPiece: public PlayingPiece{
public:
    OPiece():PlayingPiece(O){}
};

class Player{
public:
    int id; // giving them public not to declare getters and setters (no need to do this in interview not a good approach always define getters and setters)
    string name;
    PlayingPiece piece;
    Player(int id, string name, PlayingPiece piece):id(id),name(name),piece(piece){}
};

class Board{
    int size;
    vector<vector<PlayingPiece> > board;// has - a relationship with piece
public:
    Board(int size):size(size){
        board.resize(size,vector<PlayingPiece>(size,N));//initialize a board at the start with all NULL enums
    }

    // we need a function to print the current board

    void printBoard(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(board[i][j].piece==X || board[i][j].piece==O)
                    board[i][j].printPiece();
                else cout<<"_";//means an empty space
            }
            cout<<endl;//next line after one line
        }
    }

    bool hasEmptySpace(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(board[i][j].piece==N)
                    return true;
            }
        }
        return false;
    }

    // we need a function to now place a piece on the particular function
    bool addPiece(int row, int col, PlayingPiece &piece){
        if(row<0 || row>=size || col>=size || col<0 || board[row][col].piece==X || board[row][col].piece==O)
            return false;
        // now it is possible to add the piece
        board[row][col]=piece;
        return true;
    }
};

class TicTacToeGame{
    deque<Player> players;// players will play turn by turn
    Board gameBoard;
    void initializeGame(){
        XPiece x;
        Player player1(1,"Vishal",x);
        OPiece o;
        Player player2(2,"Rahul",o);
        players.push_back(player1);
        players.push_back(player2);
    }
public:
    TicTacToeGame():gameBoard(3){//constructor to initialize gameboard with size 3
        initializeGame();
    }

    string startGame(){
        bool noWinner=true;
        while(noWinner){
            Player playerTurn = players.front();
            players.pop_front();
            gameBoard.printBoard();//print the board
            if(!gameBoard.hasEmptySpace()){
                noWinner=false;
                break;//give a tie
            }
            //get user input

            cout<<playerTurn.name<<" enter row and column please";
            int row,col;
            cin>> row>>col;
            if(gameBoard.addPiece(row,col,playerTurn.piece)){//try to place the piece of the player
                players.push_back(playerTurn);//add him at last so that he will again get turn but after player 2
            }
            else{//if not placed due to some reason
                cout<< "incorrect position entered by you" << endl;
                players.push_front(playerTurn);//push him at front again so that he need to play again
                continue;// continue the flow
            }
            if(isThereWinner(playerTurn.piece.piece))
                return playerTurn.name;

                //else it goes on like this
            
        }
    }

    bool isThereWinner(Piece piece){
        // iterate over the board just check if there is a valid combination of this piece in any row , col and diagonal
        // you can write logic here
    }

};

int main(){
    TicTacToeGame *game = new TicTacToeGame();
    string winnner = game->startGame();
    cout << "Einner is" << winnner;
}