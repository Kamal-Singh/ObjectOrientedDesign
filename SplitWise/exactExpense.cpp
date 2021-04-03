#include <bits/stdc++.h>
#include "expense.hpp"
#include "exactExpense.hpp"
#include "expenseMetaData.hpp"
#include "user.hpp"
#include "split.hpp"
#include "exactSplit.hpp"
#include "utils.hpp"
using namespace std;

template<typename Base, typename T>
bool instanceof(const T*) {
    return is_base_of<Base, T>::value;
}

ExactExpense::ExactExpense(double Amount, User *paidBy, vector <Split *> splits, ExpenseMetaData *metaData = NULL): Expense(Amount,paidBy,splits,metaData) {

}
bool ExactExpense::validate() {
    for (Split * split: this->getSplits()) {
        if(!(instanceof<ExactSplit>(split)))
        {
            return false;
        }
    }

    double totalAmount = this->getAmount();
    double sumSplitAmount = 0.0;
    for(Split *split: this->getSplits()) {
        sumSplitAmount += split->getAmount();
    }
    if(totalAmount != sumSplitAmount)
        return false;

    return true;

    return true;
}