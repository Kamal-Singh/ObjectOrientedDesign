#include<bits/stdc++.h>
#include "split.hpp"
#include "equalSplit.hpp"
#include "exactSplit.hpp"
#include "percentSplit.hpp"
#include "user.hpp"
#include "expenseType.hpp"
#include "expenseManager.hpp"
#include "expense.hpp"
using namespace std;

int main() {
    ExpenseManager *expenseManager = new ExpenseManager();

    // Create Users
    User *user1 = new User("u1", "User1", "user1@mail.com", "1234567890");
    User *user2 = new User("u2", "User2", "user2@mail.com", "1234567890");
    User *user3 = new User("u3", "User3", "user3@mail.com", "1234567890");
    User *user4 = new User("u4", "User4", "user4@mail.com", "1234567890");

    // Add Users
    expenseManager->addUser(user1);    
    expenseManager->addUser(user2);    
    expenseManager->addUser(user3);    
    expenseManager->addUser(user4);

    // Run Program
    expenseManager->showAllBalance();
    expenseManager->showBalance("u1");

    vector <Split *> splits;
    splits.push_back(new EqualSplit(expenseManager->getUserMap()["u1"]));
    splits.push_back(new EqualSplit(expenseManager->getUserMap()["u2"]));
    splits.push_back(new EqualSplit(expenseManager->getUserMap()["u3"]));
    splits.push_back(new EqualSplit(expenseManager->getUserMap()["u4"]));
    expenseManager->addExpense(EQUAL, 1000, "u1", splits, NULL);

    expenseManager->showBalance("u4");
    expenseManager->showBalance("u1");

    splits.clear();
    splits.push_back(new ExactSplit(expenseManager->getUserMap()["u2"],370));
    splits.push_back(new ExactSplit(expenseManager->getUserMap()["u3"],880));
    expenseManager->addExpense(EXACT, 1250, "u1", splits, NULL);

    expenseManager->showAllBalance();

    splits.clear();
    splits.push_back(new PercentSplit(expenseManager->getUserMap()["u1"],40));
    splits.push_back(new PercentSplit(expenseManager->getUserMap()["u2"],20));
    splits.push_back(new PercentSplit(expenseManager->getUserMap()["u3"],20));
    splits.push_back(new PercentSplit(expenseManager->getUserMap()["u4"],20));
    expenseManager->addExpense(PERCENT, 1200, "u4", splits, NULL);

    expenseManager->showBalance("u1");
    expenseManager->showAllBalance();
    return 0;
}