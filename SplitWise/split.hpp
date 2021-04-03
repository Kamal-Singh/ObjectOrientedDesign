#ifndef _SPLIT_HPP_
#define _SPLIT_HPP_

#include<bits/stdc++.h>
#include "user.hpp"
using namespace std;
class Split {
    double amount;
    User *user;
    public:
    Split();
    Split(User *user);
    Split(User *user,double amount);
    int getAmount();
    void setAmount(double amount);
    User *getUser();
    void setUser(User *user);
};

#endif