#include<bits/stdc++.h>
#include "split.hpp"
#include "percentSplit.hpp"
#include "user.hpp"
using namespace std;

PercentSplit::PercentSplit(User *user,double percent): Split(user) {
    this->percent = percent;
}

double PercentSplit::getPercent() {
    return this->percent;
}

void PercentSplit::setPercent(double newPercent) {
    this->percent = newPercent;
}