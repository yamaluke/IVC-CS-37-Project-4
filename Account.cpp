/* Account.cpp */

#include<iostream>
#include<string>
#include"Account.h"

using namespace std;

//constructor for Account class 
Account::Account(string username, string status){
    this->username = username;
    this->status = status;;
}

//destrucor for account class 
Account::~Account(){
    cout << "Account removed.\n";
}

//will return the status of the Account class's user 
string Account::getStatus() const{
    return (this->status);
}