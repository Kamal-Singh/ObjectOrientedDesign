#ifndef _PERCENTEXPENSE_HPP_
#define _PERCENTEXPENSE_HPP_

#include<bits/stdc++.h>
#include "user.hpp"
#include "split.hpp"
#include "expense.hpp"
#include "percentSplit.hpp"
#include "utils.hpp"
using namespace std;

class PercentExpense: public Expense {
    public:
    PercentExpense(double Amount, User *paidBy, vector <Split *> splits, ExpenseMetaData *metaData);
    bool validate();
};

#endif
