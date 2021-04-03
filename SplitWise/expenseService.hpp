#ifndef _EXPENSESERVICE_HPP_
#define _EXPENSESERVICE_HPP_

#include <bits/stdc++.h>
#include "expenseType.hpp"
#include "expense.hpp"
#include "split.hpp"
#include "user.hpp"
using namespace std;

class ExpenseService {
    public:
    Expense *createExpense(ExpenseType expenseType, double amount, User *paidBy, vector <Split *> splits, ExpenseMetaData *expenseMetaData);
};

#endif