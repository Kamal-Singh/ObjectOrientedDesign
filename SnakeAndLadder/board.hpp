#include "tile.hpp"
#include "move.hpp"
#include <vector>
#include <algorithm>

#ifndef _BOARD_HPP_
#define _BOARD_HPP_

class Board {
    int totalTiles;
    std::vector <Tile *> tiles;
    Move move;
    public:
    Board(int totalTiles,int numberOfSnakes,int numberOfLadders);
    Board(int totalTiles, std::vector <std::pair<int,int> > SnakeDetails, std::vector <std::pair<int,int> > LadderDetails);
    int getNextMove(int curTile,int diceValue);
    int getBoardSize(); 
};

#endif