#include <bits/stdc++.h>
#include "expense.hpp"
#include "percentExpense.hpp"
#include "expenseMetaData.hpp"
#include "user.hpp"
#include "split.hpp"
#include "percentSplit.hpp"
#include "utils.hpp"
using namespace std;

template<typename Base, typename T>
bool instanceof(const T*) {
    return is_base_of<Base, T>::value;
}

PercentExpense::PercentExpense(double Amount, User *paidBy, vector <Split *> splits, ExpenseMetaData *metaData = NULL): Expense(Amount,paidBy,splits,metaData) {

}
bool PercentExpense::validate() {
    for (Split * split: this->getSplits()) {
        if(!(instanceof<PercentSplit>(split)))
        {
            return false;
        }
    }

    double totalPercent = 100;
    double sumSplitPercent = 0.0;
    for(Split *split: this->getSplits()) {
        sumSplitPercent += ((PercentSplit *)split)->getPercent();
    }
    if(totalPercent != sumSplitPercent)
        return false;

    return true;

    return true;
}