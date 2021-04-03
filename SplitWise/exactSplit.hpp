#ifndef _EXACTSPLIT_HPP_
#define _EXACTSPLIT_HPP_

#include<bits/stdc++.h>
#include "split.hpp"
#include "user.hpp"
using namespace std;

class ExactSplit: public Split{
    public:
    ExactSplit(User *user,double amount);
};

#endif