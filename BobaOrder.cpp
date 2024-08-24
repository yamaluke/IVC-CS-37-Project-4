/* BobaOrder.cpp*/

#include"BobaOrder.h"
#include"InvalidInput.h"

using namespace std;

//constructor for class BobaOrder
BobaOrder::BobaOrder(string name, string date, string phone, float miles, string shopName)
          :DeliveryOrder(name, date, phone, miles){
    this->shopName = shopName;
    this->drinksCount = 0;
}

//destructor for class BobaOrder
BobaOrder::~BobaOrder(){
    cout<<"BobaOrder destroyed.\n";
}

//will output the details of the order 
void BobaOrder::receipt() const{
    DeliveryOrder::receipt();
    cout << "\tDrinks Count: " << BobaOrder::drinksCount << endl;
}

//will return the discount amount of the order if VIP
float BobaOrder::VIPdiscount() const{
    if(this->drinksCount > 10){return 0.85;}
    if(this->drinksCount > 05){return 0.90;}
    if(this->drinksCount > 02){return 0.95;}
    return 1;
}
//will update the order balance based on the input drink name and boba and the number of drinks 
void BobaOrder::addDrink(string dName, bool boba, int count){
    float cost;
 
    if(dName == "Green Tea Latte"){
        cost = 5.8;
    }else if(dName == "Brown Sugar Boba Milk"){
        cost = 7.8;
    }else if(dName == "Brown Sugar Pearl Milk"){
        cost = 9.8;
    }else{
        throw InvalidInput(dName);
    }
    
    if (boba){
        cost += 1.5;
    }
    
    cost *= count;

    this->drinksCount += count;
    this->orderBalance += cost;
}