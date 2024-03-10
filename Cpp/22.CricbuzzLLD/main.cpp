#include<bits/stdc++.h>
using namespace std;

// using top down approach 
// for more detailed structure u can see the java one

class Match{
    Team teamA;
    Team teamB;
    MatchType type;
    vector<Inning> innings;
    Team tossWinner;

public:
    void startMatch(){

    }
};

//abstract class match type
class MatchType{
    int totalOvers;
    int bowlerAllowed;
}

class T20:public MatchType{
    //cystom logic
}
//same for one day and all

class Innings{
    Team battingTeam;
    Team bowlingTeam;
    vector<Over> overs;
    startInnings(){
    
    }
};

class Over{
    vector<Ball> balls;
    int overNumber;

    void startOver(){

    }
};

class Ball{
    int ballNo;
    BallType type;
    runtype;
    Player playedBy;
    Player bowledBy;

    BattingSCOREUPDATEOBSERVER;//observer design pattern
    BowlingSCOREUPDATEOBSERVER; // pass the player info from player bowleds by
    
};

//abstract class
class SCOREUPDATEOBSERVER{
    // updat emeyhod
};

class  BattingSCOREUPDATEOBSERVER{
    // updaye method // same
}

class BowlingSCOREUPDATEOBSERVER{
    //update method // update runs wicket and all by having ball info and player info
}

class Team{
    vector<Player> players;
    PlayerBattingController playerBattingController;
    PlayerBowlingController playerBowlingController;
};

class PlayerBattingController{
    queue<Player> yetToBat;
    Player striker;
    Player nonStriker
    //functions
    getNextBatsman(){

    }

};

class PlayerBowlingController{
    unordered_map<Player,overs> oversRem;
    queue<Player> bowlers;
    Player currentBowler;
};

class PlayeR{
    // name
    // address
    PlayerBattingScoreCard;
    PlayerBowlingScoreCard;
}

class PlayerBattingScoreCard{
    int totalRuns;
    int totalBalls;
    // etc etc
        // getters and setters

};

class PlayerBowlingScoreCard{
    int totalOvers;
    int maidens;
    int wicketsTaken;
    double economy;

    // etc etc
    // getters and setters
};


int main(){
    // flow
    // make 22 players
    // assign them to teams
    // assign teams to match 
    // in start match make two innings
    // now run the loop two times
    // in bowl over when a ball is bowled
    // call notify method of batting observer and ball observer each time with ball details
    // it should keep updating the scorecard in real time
}