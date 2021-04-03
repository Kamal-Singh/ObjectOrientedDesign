#include <bits/stdc++.h>
#include "expenseService.hpp"
#include "expenseType.hpp"
#include "user.hpp"
#include "expense.hpp"
#include "exactExpense.hpp"
#include "equalExpense.hpp"
#include "percentExpense.hpp"
#include "split.hpp"
using namespace std;


Expense *ExpenseService::createExpense(ExpenseType expenseType, double amount, User *paidBy, vector <Split *> splits, ExpenseMetaData *expenseMetaData = NULL){
    switch (expenseType) {
        case EXACT: {
            return new ExactExpense(amount,paidBy,splits,expenseMetaData);
            break;
        }
        case PERCENT: {
            for(Split *split : splits) {
                PercentSplit *percentSplit = (PercentSplit *)split;
                split->setAmount((amount*percentSplit->getPercent())/100.0);
            }
            return new PercentExpense(amount, paidBy, splits, expenseMetaData);
            break;
        }
        case EQUAL: {
            int totalSplits = (int)splits.size();
            double splitAmount = (double)(round(amount/totalSplits));
            for(Split *split: splits) {
                split->setAmount(splitAmount);
            }
            splits[0]->setAmount(splitAmount + (amount - splitAmount*totalSplits));
            return new EqualExpense(amount, paidBy, splits, expenseMetaData);
            break;
        }
        default: {
            return NULL;
        }
    }
    return NULL;
}