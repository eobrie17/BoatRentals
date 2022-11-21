//
// Created by Emma O'Brien on 10/2/22.
//

#ifndef M2OEP_EOBRIE17_MOTORBOAT_H
#define M2OEP_EOBRIE17_MOTORBOAT_H

#include <vector>
#include <string>

using std:: vector, std:: string;


class Motorboat {
protected:
    vector<bool> daysRented;
    double dailyPrice;
    string name;

public:
    /** Default constructor
   * Requires: nothing
   * Modifies: daysRented, dailyPrice, name
   * Effects:  creates a vector of 7 falses (representing 7 days of the week starting at Monday
    * where the boat has not been rented), sets daily price to $500, sets name to "Unnamed"
   */
   Motorboat();

    /** Constructor
    * Requires:  daily price
    * Modifies: daysRented vector, dailyPrice, name
    * Effects:  creates a vector of 7 falses (representing 7 days of the week starting at Monday
    * where the boat has not been rented), set the daily price, sets name
    */
    Motorboat(string n, double price);


    /** Constructor
    * Requires: days booked, daily price, name of boat
    * Modifies: daysRented vector, dailyPrice, name
    * Effects: sets the dayRented based on boolean vector (if the vector is size 7, or else
     * creates vector of 7 falses, sets the price, set the name
    */
    Motorboat(string n, vector<bool> days, double price);


    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns the name of the boat
    */
    string getName() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns boolean that tells which days boat has been rented based on the index
     * (True means rented, 0 index is Monday)
    */
    vector<bool> getDaysRented() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns daily price of the boat
    */
    double getDailyPrice() const;


    /**
    * Requires: name of the boat
    * Modifies: name
    * Effects: changes the name of the boat
    */
    void setName(string n);


    /**
    * Requires: vector of 7 booleans representing the days of the week
    * Modifies: daysRented
    * Effects: changes days rented if the vector size is 7
    */
    void setDaysRented(vector<bool> days);

    /**
    * Requires: price to rent boat for one day
    * Modifies: dailyPrice
    * Effects: sets a new dailyPrice
    */
    void setDailyPrice(double price);

    /**
    * Requires: string day of the week (Monday, Tuesday, Wednesday, etc)
    * Modifies: daysRented
    * Effects: Checks if the boat is available that day and books it if possible (sends message)
    */
    void addDay(string day);

    /**
   * Requires: nothing
   * Modifies: nothing
   * Effects: Allows you to see how the boats are different
   */
   virtual string extraParts() const;

   static const int NUMDAYS = 7;

};


#endif //M2OEP_EOBRIE17_MOTORBOAT_H
