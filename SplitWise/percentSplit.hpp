#ifndef _PERCENTSPLIT_HPP_
#define _PERCENTSPLIT_HPP_

#include<bits/stdc++.h>
#include "split.hpp"
#include "user.hpp"
using namespace std;

class PercentSplit: public Split{
    double percent;
    public:
    PercentSplit(User *user,double percent);
    double getPercent();
    void setPercent(double Percent);
};

#endif