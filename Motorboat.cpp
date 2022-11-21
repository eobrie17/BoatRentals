//
// Created by Emma O'Brien on 10/2/22.
//

#include "Motorboat.h"
#include <vector>
#include <iostream>
using namespace std;

Motorboat::Motorboat(){
    name = "Unnamed";
    daysRented = {false, false, false, false, false, false, false};
    dailyPrice = 500;
}

Motorboat::Motorboat(string n, double price){
    name = n;
    daysRented = {false, false, false, false, false, false, false};
    dailyPrice = price;
}

Motorboat::Motorboat(string n, vector<bool> days, double price){
    if (days.size() == NUMDAYS){
        daysRented = days;
    }
    else{
        daysRented = {false, false, false, false, false, false, false};
        cout << "All days are available" << endl;
    }
    name = n;
    dailyPrice = price;
}
string Motorboat::getName() const{
    return name;
}

vector<bool> Motorboat::getDaysRented() const{
    return daysRented;
}

double Motorboat::getDailyPrice() const{
    return dailyPrice;
}

void Motorboat::setName(string n){
    name = n;
}

void Motorboat::setDaysRented(vector<bool> days){
    if (days.size() != NUMDAYS){
        return;
    }
    daysRented = days;
}

void Motorboat::setDailyPrice(double price){
    dailyPrice = price;
}

void Motorboat::addDay(string day) {
    if (day == "Monday") {
        if (!daysRented[0]) {
            daysRented[0] = true;
            cout << "Booked the boat for " << day << endl;
        } else {
            cout << "The boat is not available that day. Please try another day" << endl;
        }
    } else if (day == "Tuesday") {
        if (!daysRented[1]) {
            daysRented[1] = true;
            cout << "Booked the boat for " << day << endl;
        } else {
            cout << "The boat is not available that day. Please try another day" << endl;
        }
    } else if (day == "Wednesday") {
        if (!daysRented[2]) {
            daysRented[2] = true;
            cout << "Booked the boat for " << day << endl;
        } else {
            cout << "The boat is not available that day. Please try another day" << endl;
        }
    } else if (day == "Thursday") {
        if (!daysRented[3]) {
            daysRented[3] = true;
            cout << "Booked the boat for " << day << endl;
        } else {
            cout << "The boat is not available that day. Please try another day" << endl;
        }
    } else if (day == "Friday") {
        if (!daysRented[4]) {
            daysRented[4] = true;
            cout << "Booked the boat for " << day << endl;
        } else {
            cout << "The boat is not available that day. Please try another day" << endl;
        }
    } else if (day == "Saturday") {
        if (!daysRented[5]) {
            daysRented[5] = true;
            cout << "Booked the boat for " << day << endl;
        } else {
            cout << "The boat is not available that day. Please try another day" << endl;
        }
    } else if (day == "Sunday") {
        if (!daysRented[6]) {
            daysRented[6] = true;
            cout << "Booked the boat for " << day << endl;
        } else {
            cout << "The boat is not available that day. Please try another day" << endl;
        }
    } else {
        cout << "Invalid. Please try again with a day of the week (Monday, Tuesday, Wednesday, etc)" << endl;
    }
}
 string Motorboat::extraParts() const{
    return "none";
}
