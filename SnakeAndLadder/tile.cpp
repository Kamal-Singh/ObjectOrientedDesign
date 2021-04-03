#include <iostream>
#include "tile.hpp"
#include "utils.hpp"
using namespace std;

    Tile::Tile(int tilePosition) {
        this->isLadderStart = this->isSnakeHead = -1;
        this->tilePosition = tilePosition;
    }

    void Tile::setLadder(int ladderEndPosition) {
        if(isSnakeHead == -1)
        {
            if(isLadderStart != -1)
                handleErrorAndExit("A Tile Can't have multiple Ladders");
            if(ladderEndPosition == tilePosition)
                handleErrorAndExit("A Ladder Can't end at the same Tile");
            if(ladderEndPosition < tilePosition)
                handleErrorAndExit("A Ladder Can't end on a tile with a lower position");
            isLadderStart = ladderEndPosition;
        } else {
            handleErrorAndExit("A Tile Can't have both a Snake and a Ladder");
        }
    }

    void Tile::setSnake(int snakeTailPosition) {
        if(isLadderStart == -1)
        {
            if(isSnakeHead != -1)
                handleErrorAndExit("A Tile Can't have multiple Snakes");
            if(snakeTailPosition == tilePosition)
                handleErrorAndExit("A Snake Can't have both head and Tail on the same tile");
            if(snakeTailPosition > tilePosition)
                handleErrorAndExit("A Snake Can't have tail on a tile with a higher position");
            isSnakeHead = snakeTailPosition;
        } else {
            handleErrorAndExit("A Tile Can't have both a Snake and a Ladder");
        }
    }

    bool Tile::getIsLadderStart() {
        return isLadderStart != -1;
    }

    bool Tile::getIsSnakeHead() {
        return isSnakeHead != -1;
    }

    int Tile::getLadderEndPosition() {
        return isLadderStart;
    }

    int Tile::getSnakeTailPosition() {
        return isSnakeHead;
    }
