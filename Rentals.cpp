//
// Created by Emma O'Brien on 10/2/22.
//

#include "Rentals.h"
#include <vector>

using namespace std;

Rentals:: Rentals(){
    boat = Motorboat();
    renter = "Unknown";
    phoneNumber = "000-000-0000";
}

Rentals::Rentals(Motorboat b, string name, string number){
    boat = b;
    renter=name;
    phoneNumber = number;
}

Rentals::Rentals(string n, vector<bool> days, double cost, string name, string number){
    boat = Motorboat(n, days, cost);
    renter = name;
    phoneNumber = number;
}

string Rentals::getBoat() const{
    return boat.getName();
}

string Rentals::getRenter() const{
    return renter;
}

string Rentals::getPhoneNumber() const{
    return phoneNumber;
}

void Rentals::setBoat(Motorboat b){
    boat = b;
}

void Rentals::setRenter(string name){
    renter = name;
}

void Rentals::setPhoneNumber(string number){
    phoneNumber = number;
}