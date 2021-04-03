#include<bits/stdc++.h>
#include "expenseManager.hpp"
#include "expense.hpp"
#include "user.hpp"
#include "expenseType.hpp"
#include "expenseService.hpp"
using namespace std;


ExpenseManager::ExpenseManager() {
    this->expenseService = new ExpenseService();
}

void ExpenseManager::addUser(User *newUser) {
    userMap[newUser->getId()] = newUser;
    balanceSheet[newUser->getId()];
}

map <string, User *> &ExpenseManager::getUserMap() {
    return this->userMap;
}

void ExpenseManager::addExpense(ExpenseType expenseType, double amount, string paidBy, vector <Split *> splits, ExpenseMetaData *metaData=NULL) {
    Expense *expense = expenseService->createExpense(expenseType,amount,userMap[paidBy],splits,metaData);
    expenses.push_back(expense);
    for (Split *split: splits) {
        string paidTo = split->getUser()->getId();
        map <string, double> &balances = balanceSheet[paidBy];
        if(balances.count(paidTo) == 0)
            balances[paidTo] = 0.0;
        balances[paidTo] = balances[paidTo] + split->getAmount();

        {
            map <string, double> &balances = balanceSheet[paidTo];
            if(balances.count(paidBy) == 0)
                balances[paidBy] = 0.0;
            balances[paidBy] = balances[paidBy] - split->getAmount();
        }
    }
}

void ExpenseManager::showBalance(string userId) {
    bool isEmpty = true;
    map <string, double> &balances = this->balanceSheet[userId];
    for(auto obj: balances) {
        if(obj.second != 0)
        {
            isEmpty = false;
            printBalance(userId, obj.first, obj.second);
        }
    }

    if(isEmpty)
    {
        cout<<"No Balances!"<<endl;
        return;
    }
}

void ExpenseManager::showAllBalance() {
    bool isEmpty = true;
    for(auto &allBalances: this->balanceSheet) {
        for(auto &obj: allBalances.second) {
            if(obj.second > 0)
            {
                isEmpty = false;
                printBalance(allBalances.first, obj.first, obj.second);
            }
        }
    }

    if(isEmpty)
        cout<<"No Balances!"<<endl;
}

void ExpenseManager::printBalance(string userId1,string userId2, double amount)
{
    string userName1 = userMap[userId1]->getName();
    string userName2 = userMap[userId2]->getName();
    if(amount < 0.0)
        cout<<userName1<<" owes "<<userName2<<" : "<<abs(amount)<<endl;
    else
        cout<<userName2<<" owes "<<userName1<<" : "<<abs(amount)<<endl;

}