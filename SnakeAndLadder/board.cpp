#include <bits/stdc++.h>
#include<vector>
#include "tile.hpp"
#include "move.hpp"
#include "utils.hpp"
#include "board.hpp"
using namespace std;

    Board::Board(int totalTiles,int numberOfSnakes,int numberOfLadders) {
        this->totalTiles = totalTiles;

        // Initalize the tiles with their position
        for(int i=1;i<=totalTiles;i++)
        {
            this->tiles.push_back((new Tile(i)));
        }

        // Take Snakes Input
        for(int i=0;i<numberOfSnakes;i++)
        {
            int snakeHeadPosition,snakeTailPosition;
            cout<<"Enter Details For Snake Number "<<i+1<<endl;
            cout<<"Enter it's Head Position =";
            cin>>snakeHeadPosition;
            cout<<"Enter it's Tail Position =";
            cin>>snakeTailPosition;
            this->tiles[snakeHeadPosition]->setSnake(snakeTailPosition);
        }

        // Take Ladders Input
        for(int i=0;i<numberOfLadders;i++)
        {
            int ladderStartPosition,ladderEndPosition;
            cout<<"Enter Details For Ladder Number "<<i+1<<endl;
            cout<<"Enter it's Start Position =";
            cin>>ladderStartPosition;
            cout<<"Enter it's End Position =";
            cin>>ladderEndPosition;
            this->tiles[ladderStartPosition]->setLadder(ladderEndPosition);
        }
    }

    Board::Board(int totalTiles, vector <pair<int,int> > SnakeDetails, vector <pair<int,int> > LadderDetails) {
        this->totalTiles = totalTiles;

        // Initalize the tiles with their position
        for(int i=0;i<=totalTiles;i++)
        {
            this->tiles.push_back((new Tile(i)));
        }

        for(auto snake:SnakeDetails)
        {
            this->tiles[snake.first]->setSnake(snake.second);
        }

        for(auto ladder:LadderDetails)
        {
            this->tiles[ladder.first]->setLadder(ladder.second);
        }
    }

    int Board::getNextMove(int curTile,int diceValue)
    {
        if(curTile > this->totalTiles)
            handleErrorAndExit("Invalid Tile Position");
        return this->move.getNextCellPosition(this->tiles, curTile, diceValue, this->totalTiles);
    }

    int Board::getBoardSize() {
        return this->totalTiles;
    }
