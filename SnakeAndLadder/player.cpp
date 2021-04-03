#include<iostream>
using namespace std;

class Player {
    string name;
    int curPosition;
    public:
    Player(string name,int curPosition) {
        this->name = name;
        this->curPosition = curPosition;
    }

    string getName() {
        return this->name;
    }

    int getCurPosition() {
        return this->curPosition;
    }

    int setCurPosition(int newPosition) {
        this->curPosition = newPosition;
    }
};
