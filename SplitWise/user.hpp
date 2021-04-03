#ifndef _USER_HPP_
#define _USER_HPP_

#include<bits/stdc++.h>
using namespace std;
class User {
    string id,name,email,mobileNumber;
    public:
    User(string id,string name,string email,string mobileNumber);
    string getId();
    void setId(string id);
    string getName();
    void setName(string newName);
    string getEmail();
    void setEmail(string newEmail);
    string getMobileNumber();
    void setMobileNumber(string newMobileNumber);
};

#endif