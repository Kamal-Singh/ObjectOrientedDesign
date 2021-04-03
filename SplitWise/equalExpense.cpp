#include <bits/stdc++.h>
#include "expense.hpp"
#include "equalExpense.hpp"
#include "expenseMetaData.hpp"
#include "user.hpp"
#include "split.hpp"
#include "equalSplit.hpp"
#include "utils.hpp"
using namespace std;

template<typename Base, typename T>
bool instanceof(const T*) {
    return is_base_of<Base, T>::value;
}

EqualExpense::EqualExpense(double Amount, User *paidBy, vector <Split *> splits, ExpenseMetaData *metaData = NULL): Expense(Amount,paidBy,splits,metaData) {

}
bool EqualExpense::validate() {
    for (Split * split: this->getSplits()) {
        if(!(instanceof<EqualSplit>(split)))
        {
            return false;
        }
    }

    return true;
}