#ifndef _EXPENSE_HPP_
#define _EXPENSE_HPP_

#include<bits/stdc++.h>
#include "split.hpp"
#include "user.hpp"
#include "expenseMetaData.hpp"
using namespace std;

class Expense {
    string id;
    double amount;
    User *paidBy;
    vector <Split *> splits;
    ExpenseMetaData *metadata;
    public:
    Expense(double amount,User *paidBy,vector <Split *> &splits,ExpenseMetaData *metaData);
    string getId();
    void setId(string newId);
    double getAmount();
    void setAmount(double newAmount);
    vector <Split *> getSplits();
    void setSplits(vector <Split *> newSplits);
    ExpenseMetaData *getMetaData();
    void setMetaData(ExpenseMetaData *newMetaData);
    bool virtual validate();
};

#endif