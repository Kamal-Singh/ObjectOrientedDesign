#include <vector>
#include "tile.hpp"
#ifndef _MOVE_HPP_
#define _MOVE_HPP_

class Move {
    public:
    int getNextCellPosition(std::vector <Tile *> &tiles, int curTile, int diceValue, int boardSize);
};

#endif