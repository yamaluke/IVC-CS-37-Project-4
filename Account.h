/* Account.h */

#include<iostream>
#include<string>

using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
private:
    string username;       //username of user
    string status;         //account status of user (Regular, Owner, VIP)

public:
    Account(string username, string status = "Regular");    //constructor for class
    ~Account();                                             //destructor for class

    string getStatus() const;                               //will return the status for user

};

#endif      //end of class declartion Account