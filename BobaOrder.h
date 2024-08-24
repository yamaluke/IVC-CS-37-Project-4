/* BobaOrder.h */

#include<iostream>
#include<string>
#include"DeliveryOrder.h"


using namespace std;

#ifndef BOBAORDER_H
#define BOBAORDER_H

//class will inherit from DeliverOrder class
class BobaOrder : public DeliveryOrder{
private:
    string shopName;    //name of the shop
    int drinksCount;    //number of drinks ordered 

public:
    BobaOrder(string name, string date, string phone, float miles, string shopName);    //constructor for class
    ~BobaOrder();                                                                       //destructor for class

    void receipt() const;                                                               //will output the details of the order 
    float VIPdiscount() const;                                                          //will return the discount amount of the order if VIP
    void addDrink(string dName, bool boba = true, int count = 1);                       //will update the order balance based on the input drink name (dName) and boba and the number of drinks (if function failed, will throw an InvalidInput exception class)
};

#endif      //end of class declaration BobaOrder