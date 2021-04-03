#include<bits/stdc++.h>
#include "split.hpp"
#include "user.hpp"
using namespace std;

Split::Split() {
    this->user = NULL;
    this->amount = 0.0;
}
Split::Split(User *user) {
    Split();
    this->user = user;
}
Split::Split(User *user,double amount) {
    this->user = user;
    this->amount = amount;
}

int Split::getAmount() {
    return this->amount;
}

void Split::setAmount(double amount) {
    this->amount = amount;
}

User * Split::getUser() {
    return this->user;
}

void Split::setUser(User *user) {
    this->user = user;
}
