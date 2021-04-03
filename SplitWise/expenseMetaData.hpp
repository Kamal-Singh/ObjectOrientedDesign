#ifndef _EXPENSEMETADATA_HPP_
#define _EXPENSEMETADATA_HPP_

#include<bits/stdc++.h>
using namespace std;

class ExpenseMetaData {
    string name,notes,imageUrl;
    public:
    ExpenseMetaData(string name,string notes,string imageUrl);
    string getName();
    void setName(string newName);
    string getNotes();
    void setNotes(string newNotes);
    string getImageUrl();
    void setImageUrl(string newImageUrl);
};

#endif
