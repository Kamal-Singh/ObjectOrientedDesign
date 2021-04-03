#include<bits/stdc++.h>
#include "user.hpp"
using namespace std;


User::User(string id,string name,string email,string mobileNumber) {
    this->id = id;
    this->name = name;
    this->email = email;
    this->mobileNumber = mobileNumber;
}

string User::getId() {
    return this->id;
}

void User::setId(string id) {
    this->id = id;
}

string User::getName() {
    return this->name;
}

void User::setName(string newName) {
    this->name = newName;
}

string User::getEmail() {
    return this->email;
}

void User::setEmail(string newEmail) {
    this->email = newEmail;
}

string User::getMobileNumber() {
    return this->mobileNumber;
}

void User::setMobileNumber(string newMobileNumber) {
    this->mobileNumber = newMobileNumber;
}
