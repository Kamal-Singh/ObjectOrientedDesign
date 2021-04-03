#include<iostream>
#include "utils.hpp"
using namespace std;

class Dice {
    int minValue,maxValue;
    public:
    Dice() {
        srand(time(NULL));
        this->minValue = 1;
        this->maxValue = 6;
    }

    Dice(int minValue,int maxValue) {
        Dice();
        if(minValue <= 0)
            handleErrorAndExit("The Dice can't have value less than 0");

        this->minValue = minValue;
        this->maxValue = maxValue;
    }

    int throwDice() {
        return (rand()%(maxValue-minValue+1)) + minValue;
    }
};