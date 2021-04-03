#ifndef _TILE_HPP_
#define _TILE_HPP_

class Tile {
    int isLadderStart,isSnakeHead,tilePosition;
    public:
    Tile(int tilePosition);

    void setLadder(int ladderEndPosition);
    void setSnake(int snakeTailPosition);
    bool getIsLadderStart();
    bool getIsSnakeHead();
    int getLadderEndPosition();
    int getSnakeTailPosition();
};

#endif