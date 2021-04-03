#ifndef _EXPENSEMANAGER_HPP_
#define _EXPENSEMANAGER_HPP_

#include<bits/stdc++.h>
#include "expense.hpp"
#include "user.hpp"
#include "expenseType.hpp"
#include "expenseService.hpp"
using namespace std;

class ExpenseManager {
    vector <Expense *> expenses;
    map <string, User *> userMap;
    map <string, map <string, double> > balanceSheet;
    ExpenseService *expenseService;
    public:
    ExpenseManager();
    map <string, User *> &getUserMap();
    void addUser(User *newUser);
    void addExpense(ExpenseType expenseType, double amount, string paidBy, vector <Split *> splits, ExpenseMetaData *metaData);
    void showBalance(string userId);
    void showAllBalance();
    void printBalance(string userId1,string userId2, double amount);
};

#endif