#include<bits/stdc++.h>
#include<iostream>

#include "player.cpp"
#include "dice.cpp"
#include "board.hpp"
#include "utils.hpp"
using namespace std;

// Assumption for the Snake and Ladder Game
/*
1. The game will ends when only one player remains and all the other players have reached 100 or end of the board
2. The input is valid
3. In case of any invalid input the program will show an message and terminate
*/

class SnakeAndLadderGame;

// Will Simulate the Snake and Ladder Game
class SnakeAndLadderGame {
    Board *board;
    deque <Player *> players;
    Dice *dice;
    bool isGameFinished;
    vector <Player *> winners;
    public:
    SnakeAndLadderGame(vector <Player *> &players, Board *board, Dice *dice = new Dice())
    {
        if(players.size() == 0)
            handleErrorAndExit("Number of Players can't be less than 1");

        if(board->getBoardSize() <= 0)
            handleErrorAndExit("Board Size can't be less than 1");

        this->isGameFinished = false;
        // Intialize Players
        for(auto i: players) {
            this->players.push_back(i);
        }

        this->board = board;
        this->dice = dice;
    }

    Player *getCurrentPlayer() {
        if(this->players.size() == 0)
            handleErrorAndExit("There are no players to play the game");
        return this->players.front();   
    } 

    Player *removeCurrentPlayer() {
        if(this->players.size() == 0)
            handleErrorAndExit("There are no players to play the game");
        Player *front = this->players.front();
        this->players.pop_front();
        return front;
    }

    void cyclePlayers(int diceValue) {
        if(this->players.size() == 0)
            handleErrorAndExit("There are no players to play the game");

        if(diceValue == 6)
            return;

        Player *front = this->players.front();
        this->players.pop_front();
        this->players.push_back(front);
    }

    void gameFinished() {
        cout<<"The Game Has Finished"<<endl;
        cout<<"The Ranks of Players:"<<endl;
        cout<<"Name\t\t\tRank"<<endl;
        for(int i=0;i<this->winners.size();i++)
        {
            cout<<(this->winners[i]->getName())<<"\t\t\t"<<(i+1)<<endl;
        }
    }

    void printMove(Player *player, int diceValue, int newTile) {
        cout<<(player->getName())<<" got "<<diceValue<<" from dice, moving from "<<(player->getCurPosition())<<" to "<<newTile<<endl;
    }

    void playGame() {
        while(!isGameFinished) {
            if(this->players.size() <= 0)
                handleErrorAndExit("There are no players to play the game");
            if(this->players.size() <= 1)
            {
                cout<<"Player "<<(this->getCurrentPlayer()->getName())<<" is the only one Left, Ending Game"<<endl;
                this->isGameFinished = true;
                this->winners.push_back(this->getCurrentPlayer());
                break;
            }

            Player *curPlayer = this->getCurrentPlayer();

            if(curPlayer->getCurPosition() == this->board->getBoardSize())
            {
                this->winners.push_back(this->getCurrentPlayer());
                this->removeCurrentPlayer();
                continue;
            }

            int diceValue = this->dice->throwDice();
            int nextMove = this->board->getNextMove(curPlayer->getCurPosition(), diceValue);
            printMove(curPlayer, diceValue, nextMove);
            curPlayer->setCurPosition(nextMove);

            if(curPlayer->getCurPosition() == this->board->getBoardSize())
            {
                cout<<"Player "<<(curPlayer->getName())<<" has reached the end of the board"<<endl;
                this->winners.push_back(this->getCurrentPlayer());
                this->removeCurrentPlayer();
                continue;
            }

            this->cyclePlayers(diceValue);
        }
        this->gameFinished();
    }   
};

int main() {
    int numberOfPlayers, numberOfSnakes, numberOfLadders;
    // cout<<"Enter Number Of Players ="<<endl;
    // cin>>numberOfPlayers;
    // vector <Player *> players;
    // for(int i=0;i<numberOfPlayers;i++)
    // {
    //     string name;
    //     cout<<"Enter Name="<<endl;
    //     cin>>name;
    //     players[i] = new Player(name,1);
    // }

    // cout<<"Enter Number Of Snakes ="<<endl;
    // cin>>numberOfSnakes;

    vector <Player *> players;
    players.push_back(new Player("Kamal", 1));
    players.push_back(new Player("Test", 1));
    players.push_back(new Player("KKK", 1));

    vector <pair<int,int> > snakeDetails, ladderDetails;
    snakeDetails.push_back({62,18});
    snakeDetails.push_back({36,6});
    snakeDetails.push_back({32,10});
    snakeDetails.push_back({88,24});
    snakeDetails.push_back({95,56});
    snakeDetails.push_back({97,78});

    ladderDetails.push_back({1,38});
    ladderDetails.push_back({4,14});
    ladderDetails.push_back({8,30});
    ladderDetails.push_back({21,42});
    ladderDetails.push_back({28,76});
    ladderDetails.push_back({50,67});
    ladderDetails.push_back({71,92});
    ladderDetails.push_back({80,99});

    Board *board = new Board(100, snakeDetails, ladderDetails);

    SnakeAndLadderGame game(players,board);

    game.playGame();

    return 0;
}