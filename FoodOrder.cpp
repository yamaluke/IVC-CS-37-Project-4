/* FoodOrder.cpp */
#include"FoodOrder.h"
#include"InvalidInput.h"

//constructor for class FoodOrder
FoodOrder::FoodOrder(string name, string date, string phone, float miles, string sName)
          :DeliveryOrder(name, date, phone, miles){
    this->restaurantName = sName;
    this->foodCount = 0;
}

//destructor for class FoodOrder
FoodOrder::~FoodOrder(){
    cout << "FoodOrder destroyed.\n";
}

//will output the details of the order 
void FoodOrder::receipt() const{
    DeliveryOrder::receipt();
    cout << "\tFood Count: " << foodCount << endl;
}

//will return the discount amount of the order if VIP
float FoodOrder::VIPdiscount() const{
    if(DeliveryOrder::orderBalance > 50){return .85;}
    if(DeliveryOrder::orderBalance > 30){return .90;}
    if(DeliveryOrder::orderBalance > 20){return .95;}
    return 1;
}

//will update the order balance based on the input drink name and boba and the number of drinks 
void FoodOrder::addFood(string food, int sides, bool soup){
    float cost;

    if(food == "Thick Cauliflower Steaks"){
        cost = 15;
    }else if(food == "Rack of Lamb"){
        cost = 38;
    }else if(food == "Organic Scottish Salmon"){
        cost = 23;
    }else if(food == "Grilled Lobster Risotto"){
        cost = 46;
    }else{
        throw InvalidInput(food);
    }

    cost += sides * 6;

    if (soup){
        cost += 5;
    }

    this->foodCount++;
    this->orderBalance += cost;
}