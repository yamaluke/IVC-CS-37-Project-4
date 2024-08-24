/* DeliverOrder.cpp */

#include "DeliveryOrder.h"

/******************/
/* static members */
/******************/
//==Variables==// ++ initialization 
int DeliveryOrder::orderCount = 0;
const float DeliveryOrder::taxRate = 0.09;
const float DeliveryOrder::deliveryRate = 1.5;

//==functions==//
//will return the total number of orders created 
int DeliveryOrder::getOrderCount(){
    return DeliveryOrder::orderCount;
}


/****************/
/*  non-static  */
/*   functions  */
/****************/
//constructor for deliveryorder class
DeliveryOrder::DeliveryOrder(string name, string date, string phone, float miles){
    this->name = name;
    this->date = date;
    this->phone = phone;
    this->miles = miles;

    this->orderBalance = 0;

    DeliveryOrder::orderCount++;
}

//destructor for deliveryorder class
DeliveryOrder::~DeliveryOrder(){
    cout << "DeliveryOrder destroyed.\n";
}

//will output the details of the order 
void DeliveryOrder::receipt() const{
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << "\tOrder Balance: $" << orderBalance << endl;
}

//will return the orderbalance 
float DeliveryOrder::getTotalBalance() const{
    float totalBalance;
    totalBalance = this->orderBalance * (1 + DeliveryOrder::taxRate) + this->miles * DeliveryOrder::deliveryRate;
    return totalBalance;
}