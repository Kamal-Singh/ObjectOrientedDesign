#include<bits/stdc++.h>
#include "expense.hpp"
#include "expenseMetaData.hpp"
#include "split.hpp"
using namespace std;

Expense::Expense(double amount,User *paidBy,vector <Split *> &splits,ExpenseMetaData *metaData = NULL) {
    this->id = "";
    this->amount = amount;
    this->paidBy = paidBy;
    this->splits = splits;
    this->metadata = metadata;
}

string Expense::getId()
{
    return this->id;
}

void Expense::setId(string newId)
{
    this->id = newId;
}

double Expense::getAmount()
{
    return this->amount;
}

void Expense::setAmount(double newAmount)
{
    this->amount = newAmount;
}

vector <Split *> Expense::getSplits()
{
    return this->splits;
}

void Expense::setSplits(vector <Split *> newSplits)
{
    this->splits = newSplits;
}

ExpenseMetaData *Expense::getMetaData()
{
    return this->metadata;
}

void Expense::setMetaData(ExpenseMetaData *newMetaData)
{
    this->metadata = newMetaData;
}

bool Expense::validate(){}