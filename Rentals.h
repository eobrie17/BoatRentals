//
// Created by Emma O'Brien on 10/2/22.
//

#ifndef M2OEP_EOBRIE17_RENTALS_H
#define M2OEP_EOBRIE17_RENTALS_H

//#include "Motorboat.h"
#include "Pontoon.h"
#include <string>
#include <vector>
using std::string, std::vector;

/*
 * This program helps you plan to rent one boat for one week at your boat rental company.
 *
 */

class Rentals {
    private:
        Motorboat boat;
        string renter;
        string phoneNumber;
    public:
        /** Default constructor
        * Requires: nothing
        * Modifies: nothing
        * Effects: creates a Motorboat object, sets renter to Unknown,
        * and phone number to 000-000-0000
       */
        Rentals();

        /** Constructor
        * Requires: Motorboat object, renter name, renter phone number
        * Modifies: nothing
        * Effects: sets boat, renter, phoneNumber
        */
        Rentals(Motorboat b, string name, string number);


        /** Constructor
        * Requires: name of boat, days rented, cost of boat, renter name, renter phone number
        * Modifies: nothing
        * Effects: sets boat, renter, phoneNumber
        */
        Rentals(string n, vector<bool> days, double cost, string name, string number);


        /**
        * Requires: nothing
        * Modifies: nothing
        * Effects: returns boat name
        */
        string getBoat() const;


        /**
        * Requires: nothing
        * Modifies: nothing
        * Effects: returns the renter's name
        */
        string getRenter() const;


        /**
        * Requires: nothing
        * Modifies: nothing
        * Effects: returns the renter's phone number
        */
        string getPhoneNumber() const;


        /**
        * Requires: Motorboat objects
        * Modifies: boat
        * Effects: sets boat if the dates are compatible, if not print message
        */
        void setBoat(Motorboat b);


        /**
        * Requires: renter's name
        * Modifies: renter
        * Effects: sets the renter's name
        */
        void setRenter(string name);


        /**
        * Requires: renter's phone number
        * Modifies: phoneNumber
        * Effects: sets the renter's phone number
        */
        void setPhoneNumber(string number);



    };


#endif //M2OEP_EOBRIE17_RENTALS_H
