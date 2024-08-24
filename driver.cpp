/**********************************************/
/*Creator:  Luke Yamaguchi                    */
/*Date:     03/26/2023                        */
/*File:     driver.cpp                        */
/*Purpose:  Project 4 for CS 37 course at IVC */
/**********************************************/

#include<iostream>
#include<string>
#include<iomanip>

#include "InvalidInput.h"
#include "DeliveryOrder.h"
#include "BobaOrder.h"
#include"FoodOrder.h"
#include"Account.h"

using namespace std;

//==prototypes==/
float applyDiscount(DeliveryOrder *order, const Account& userAccount);

/************/
/*  Driver  */
/************/
int main(){
    //==Declaration==//
    const Account Stuart("Stwart", "Owner");
    Account Kevin("Kevin", "VIP");
    Account Bob("Bob");

    DeliveryOrder* deliveryOPointter;   //pointer for each order 

    //==Kevin Order==//
    cout << "Kevin placing order.\n";
    BobaOrder MTeaOrder("Kevin", "11/20/2022", "123-456-0000", 10.4, "M Tea");

    //adding drinks 
    try{
        MTeaOrder.addDrink("Green Tea Latte"); 
        MTeaOrder.addDrink("Brown Sugar Pearl Milk", false);
        MTeaOrder.addDrink("Brown Sugar Boba Milk", false, 2);
        MTeaOrder.addDrink("Iron Goddess");
    }
    catch(InvalidInput& error){
        error.print_reason();
        cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }
    
    //output 
    cout << setprecision(2) << fixed;
    MTeaOrder.receipt();
    cout << "Balance: $" << MTeaOrder.getTotalBalance() << endl;
    deliveryOPointter = &MTeaOrder;
    cout << "Discounted Balance: $" << applyDiscount(deliveryOPointter, Kevin) << "\n\n\n";
    
    //==Stuart order==//
    cout << "Stuart placing order.\n";
    FoodOrder TGreenOrder("Stuart", "11/20/2022", "123-456-1111", 25.5, "Tavern Green");

    //adding food 
    try{
        TGreenOrder.addFood("Thick Cauliflower Steaks", 1, true);
        TGreenOrder.addFood("Organic Scottish Salmon");
        TGreenOrder.addFood("Rack of Lamb", 0, true);
    }
    catch(InvalidInput& error){
        error.print_reason();
        cout << "Not serving requested food. Food order ignored.\n\n";
    }
    
    //output
    TGreenOrder.receipt();
    cout << "Balance: $" << TGreenOrder.getTotalBalance() << endl;
    deliveryOPointter = &TGreenOrder;
    cout << "Discounted Balance: $" << applyDiscount(deliveryOPointter, Stuart) << "\n\n\n";   

    //==Bob order==//
    cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";

    //test reciept / output 
    TGreenOrder.receipt();
    cout << "Balance: $" << TGreenOrder.getTotalBalance() << endl;
    deliveryOPointter = &TGreenOrder;
    cout << "Discounted Balance: $" << applyDiscount(deliveryOPointter, Bob) << endl;   

    cout << "Bob upset, cancelling order :(\n\n";

    //==final output==//
    cout << "Total order placed: " << DeliveryOrder::getOrderCount() << ".\n\n";


}

//will return the total cost of the order with the discounts applied 
float applyDiscount(DeliveryOrder *order, const Account& userAccount){
    string status = userAccount.getStatus();

    if(status == "Owner"){
        float cost = order->getTotalBalance();
        cost *= .1;
        return cost;
    }else if(status == "VIP"){
        float cost = order->getTotalBalance();
        float rate = order->VIPdiscount();
        cost *= rate;
        return cost;
    }else{
        float cost = order->getTotalBalance();
        return cost;
    }
}