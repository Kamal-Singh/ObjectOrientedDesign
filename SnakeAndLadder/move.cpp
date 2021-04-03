#include<iostream>
#include "tile.hpp"
#include "move.hpp"
#include "utils.hpp"
using namespace std;

    int Move::getNextCellPosition(vector <Tile *> &tiles, int curTile, int diceValue, int boardSize) {
        int nextPosition = curTile + diceValue;
        if(nextPosition > boardSize)
            nextPosition = curTile;
        
        if(tiles[nextPosition]->getIsLadderStart())
        {
            cout<<"Took a Ladder"<<endl;
            return tiles[nextPosition]->getLadderEndPosition();
        }

        if(tiles[nextPosition]->getIsSnakeHead())
        {
            cout<<"Bitten By A Snake"<<endl;
            return tiles[nextPosition]->getSnakeTailPosition();
        }

        return nextPosition;
    }