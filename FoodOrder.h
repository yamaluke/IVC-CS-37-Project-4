/* FoodOrder.h */

#include<iostream>
#include<string>
#include"DeliveryOrder.h"

using namespace std;

#ifndef FOODORDER_H
#define FOODORDER_H

//derived class that inherits from deliveryorder 
class FoodOrder : public DeliveryOrder{
private:
    string restaurantName;      //name of restaurant 
    int foodCount;              //number of food in order 

public:
    FoodOrder(string name, string date, string phone, float miles, string sName);   //constructor 
    ~FoodOrder();               //destructor 

    void receipt() const;       //will output the details of the order 
    float VIPdiscount() const;  //will return the discount amount of the order if VIP
    void addFood(string Name, int sides = 0, bool soup = false);    //will update the order balance based on the input drink name and boba and the number of drinks 
};


#endif