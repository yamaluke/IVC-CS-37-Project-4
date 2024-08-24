/* InvalidInput.h */

#include<string>
#include<iostream>

using namespace std;

#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

class InvalidInput{
private:
    const string MESSAGE;   //the message that will pop up 
public:
    //constructor for class, will initialize the message variable 
    InvalidInput(string iMessage) : MESSAGE("Invalid input \"" + iMessage + "\".\n"){}; 

    //function that prints out the message 
    void print_reason(){
        cout << MESSAGE;
    }
};

#endif //end of class declaration InvalidInput