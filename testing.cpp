//
// Created by Emma O'Brien on 10/12/22.
//
#include "Rentals.h"
#include <iostream>
using namespace std;

bool test_Rentals();
bool test_Motorboat();
bool test_Pontoon();

int main() {
    if (test_Rentals()) {
        cout << "Passed all Rental test cases" << endl;
    }
    if (test_Motorboat()) {
        cout << "Passed all Motorboat test cases" << endl;
    }
    if (test_Pontoon()) {
        cout << "Passed all Pontoon test cases" << endl;
    }
    return 0;
}


bool test_Rentals() {
    bool passed = true;
    Rentals r1;
    if (r1.getRenter() != "Unknown" && r1.getPhoneNumber() != "000-000-0000") {
        passed = false;
        cout << "FAILED Rentals default constructor test case" << endl;
    }
    Motorboat b1;
    Rentals r2( b1, "John Smith", "603-779-2387");
    if (r2.getBoat() != "Unnamed" ) {
        passed = false;
        cout << "FAILED Rentals overloaded constructor test case" << endl;
    }
    return passed;
}

bool test_Motorboat() {
    bool passed = true;
    Motorboat b1;
    if (b1.getDailyPrice() != 500 && b1.getName() != "Unnamed") {
        passed = false;
        cout << "FAILED Motorboat default constructor test case" << endl;
    }
    b1.addDay("monday");
    for (bool d: b1.getDaysRented()) {
        if (d) {
            passed = false;
            cout << "FAILED Motorboat add invalid day test case" << endl;
        }
    }
    b1.addDay("Monday");
    vector<bool> daysRented2 = b1.getDaysRented();
    for (int i=0; i<daysRented2.size(); i++) {
        if (!daysRented2[0]) {
            passed = false;
            cout << "FAILED Motorboat add Monday day test case" << endl;
        }
    }
    b1.addDay("Monday");
    vector<bool> daysRented3 = b1.getDaysRented();
    for (int i=0; i<daysRented3.size(); i++) {
        if (!daysRented2[0]) {
            passed = false;
            cout << "FAILED Motorboat add same day test case" << endl;
        }
    }
    Motorboat b2;
    vector<bool> days = {false,false,false,false,false,true,true,true};
    b2.setDaysRented(days);
    if(b2.getDaysRented().size() != 7){
        passed=false;
        cout << "FAILED add too many days test case" << endl;
    }
    return passed;
}

bool test_Pontoon(){
    bool passed=true;
    Pontoon p1;
    if(p1.getPontoons() != 2){
        passed=false;
        cout << "FAILED Pontoon default constructor test case" << endl;
    }
    Pontoon p2("USS Something", 1000, 3);
    if(p2.getPontoons() != 3 && p2.getDailyPrice() != 1000){
        passed=false;
        cout << "FAILED Pontoon overloaded constructor test case" << endl;
    }
    if(p2.extraParts() != "pontoons"){
        passed=false;
        cout << "FAILED Pontoon extra parts test case" << endl;
    }
    return passed;

}