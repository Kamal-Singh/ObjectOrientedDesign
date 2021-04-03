#include<bits/stdc++.h>
#include "expenseMetaData.hpp"
using namespace std;

ExpenseMetaData::ExpenseMetaData(string name,string notes,string imageUrl){
    this->name = name;
    this->notes = notes;
    this->imageUrl = imageUrl;
}

string ExpenseMetaData::getName() {
    return this->name;
}

void ExpenseMetaData::setName(string newName) {
    this->name = newName;
}

string ExpenseMetaData::getNotes() {
    return this->notes;
}

void ExpenseMetaData::setNotes(string newNotes) {
    this->notes = newNotes;
}

string ExpenseMetaData::getImageUrl() {
    return this->imageUrl;
}

void ExpenseMetaData::setImageUrl(string newImageUrl) {
    this->imageUrl = newImageUrl;
}
