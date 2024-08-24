/* DeliveryOrder.h */

#include<iostream>
#include<string>

using namespace std;

#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

class DeliveryOrder{
private:
    static int orderCount;              //total number of orders recieved
    static const float taxRate;         //the tax rate for purchases
    static const float deliveryRate;    //the delivery costs 

    string name;                        //customer's name
    string date;                        //date of the order 
    string phone;                       //customer phone number
    float miles;                        //distance for delivery in miles 

protected:
    float orderBalance;                 //the cost of the order, not including the delivery fees and the tax 

public: 
    static int getOrderCount();         //will return the total number of orders created 

    DeliveryOrder(string name, string date, string phone, float miles); //constructor for DeliverOrder
    ~DeliveryOrder();                   //destructor for DeliveryOrder

    void receipt() const;               //will output the details of the order 
    float getTotalBalance() const;      //will return the orderbalance 

    virtual float VIPdiscount() const = 0;  //pure virtual function that needs to be implemented in derived class, should return value of vip discount 
};

#endif