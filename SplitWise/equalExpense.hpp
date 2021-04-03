#ifndef _EQUALEXPENSE_HPP_
#define _EQUALEXPENSE_HPP_

#include<bits/stdc++.h>
#include "user.hpp"
#include "split.hpp"
#include "equalSplit.hpp"
#include "utils.hpp"
using namespace std;

class EqualExpense: public Expense {
    public:
    EqualExpense(double Amount, User *paidBy, vector <Split *> splits, ExpenseMetaData *metaData);
    bool validate();
};

#endif
