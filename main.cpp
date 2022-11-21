//
// Created by Emma O'Brien on 10/2/22.
//
#include "Rentals.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main () {
    // Use a file to input all boat that the company has
    ifstream inFile("../BoatData.txt");
    //output file
    ofstream outFile;
    outFile.open("RenterInfo.txt");
    //number of renters
    int numRenters= 1;

    //vector to hold all the boats
    vector<shared_ptr<Motorboat>> fleet;

    int numBoats= 0;
    string pontoon;
    string name;
    int numPontoons;
    double price;
    string newline;

    if (inFile){
        inFile >> numBoats;
        getline(inFile, newline);
        for (int i=0; i < numBoats; i++){
            //Y if pontoon, N if motorboat
            getline(inFile, pontoon);
            if (pontoon == "Y"){
                getline(inFile, name);
                inFile >> price;
                getline(inFile, newline);
                inFile >> numPontoons;
                getline(inFile, newline);
                fleet.push_back(make_shared<Pontoon>(name, price, numPontoons));
            }
            else{
                getline(inFile, name);
                inFile >> price;
                getline(inFile, newline);
                fleet.push_back(make_shared<Motorboat>(name, price));
            }
        }
    }



    //variable to continue
    bool continueBooking = true;
    while (continueBooking){
        //customer interface
        string answer;
        string day;
        cout << "Would you like to rent a Motorboat (enter 1) or Pontoon boat (enter 2): ";
        getline(cin, answer);
        //input validation
        while (answer.length() != 1 && !isdigit(answer[0]) || answer!="1" && answer!="2"){
            cout << "Invalid input. Please enter a 1 for Motorboat or 2 for Pontoon boat: ";
            getline(cin, answer);
        }
        //filter fleet for the type of boat
        vector<shared_ptr<Motorboat>> myFleet;

        //filter for pontoon boats
        if(answer == "2"){
            for (shared_ptr<Motorboat>& boat: fleet){
                if (boat->extraParts() == "pontoons"){
                    myFleet.push_back(boat);
                }
            }
        }
            //filter for regular motorboats
        else{
            for (shared_ptr<Motorboat>& boat: fleet){
                if (boat->extraParts() == "none"){
                    myFleet.push_back(boat);
                }
            }
        }

        //Ask what day they want to rent it for
        cout << "Enter the day you want to rent the boat (Monday, Tuesday, Wednesday, etc): ";
        getline(cin, day);
        //input validation
        while (day != "Monday"
               && day != "Tuesday"
               && day != "Wednesday"
               && day != "Thursday"
               && day != "Friday"
               && day != "Saturday"
               && day != "Sunday"){
            cout << "Invalid input. Please type out the full name of the weekday (with the first letter capitalized): ";
            getline(cin, day);
        }

        //loop through vector see which boats there are
        cout << "We have ";
        for (int i=0; i < myFleet.size(); i++){
            if (i == myFleet.size()-1){
                cout<< myFleet[i]->getName()<< " for $"<< myFleet[i]->getDailyPrice() << endl;
            }
            else{
                cout<< myFleet[i]->getName()<< " for $" << myFleet[i]->getDailyPrice() << " and ";
            }
        }

        //ask which one
        string choice;
        shared_ptr<Motorboat> saveBoat;
        bool keepGoing = true;
        cout <<"Please enter the name of the boat you want to rent(enter the name exactly): ";
        cin.clear();
        getline(cin, choice);


        while (keepGoing){
            for (int i=0; i < myFleet.size(); i++){
                if (myFleet[i]->getName() == choice){
                    myFleet[i]->addDay(day);
                    saveBoat = myFleet[i];
                    keepGoing = false;
                }
            }
            if(keepGoing){
                cout << "Boat was not found. Please enter a boat name exactly: ";
                cin.clear();
                getline(cin, choice);
            }
        }
        //ask for information
        string name;
        string phone;
        //name
        cout << "Please enter your name: ";
        getline(cin, name);
        //validation
        bool bad = true;
        while (bad) {
            for (char c: name) {
                if (isalpha(c) || c == ' ') {
                    bad=false;
                }
                else{
                    cout << "Invalid. Please enter your name: ";
                    getline(cin, name);
                }
            }
        }

        //phone number
        cout << "Please enter your phone number in the format 000-000-0000: ";
        getline(cin, phone);
        //validation
        bool bad2 = true;
        while (bad2) {
            for (char n: phone) {
                if (phone.length() == 12 && !isalpha(n) || n == '-') {
                    bad2=false;
                }
                else{
                    cout << "Invalid. Please enter your phone number in format 000-000-0000: ";
                    getline(cin, phone);
                }
            }
        }

        //create Rentals object
        Rentals r(*saveBoat, name, phone);


        //ask if they want to continue
        string decision;
        cout << "Do you want to continue to book more days? (Enter Y or N): ";
        getline(cin, decision);
        //input validation
        while (decision.length() != 1 && !isdigit(decision[0]) || decision != "Y" && decision != "N"){
            cout << "Invalid input. Please enter Y to continue or N to stop: ";
            getline(cin, decision);
        }
        if (decision == "N"){
            continueBooking =false;
        }

        //print to outfile
        outFile << "Renter #" << numRenters << " Information:"<< endl;
        outFile <<"Name: "<< r.getRenter() << endl;
        outFile << "Phone number: " << r.getPhoneNumber()<< endl;
        outFile << "Boat: " << r.getBoat() << endl;
        outFile << "Day: " << day << endl << endl;
        //incrementer renters
        ++numRenters;

    }
    outFile.close();
    return 0;
}