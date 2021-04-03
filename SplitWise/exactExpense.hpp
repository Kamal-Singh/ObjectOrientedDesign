#ifndef _EXACTEXPENSE_HPP_
#define _EXACTEXPENSE_HPP_

#include<bits/stdc++.h>
#include "user.hpp"
#include "split.hpp"
#include "expense.hpp"
#include "exactSplit.hpp"
#include "utils.hpp"
using namespace std;

class ExactExpense: public Expense {
    public:
    ExactExpense(double Amount, User *paidBy, vector <Split *> splits, ExpenseMetaData *metaData);
    bool validate();
};

#endif
