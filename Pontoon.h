//
// Created by Emma O'Brien on 10/2/22.
//

#ifndef M2OEP_EOBRIE17_PONTOON_H
#define M2OEP_EOBRIE17_PONTOON_H
#include "Motorboat.h"

class Pontoon : public Motorboat {
private:
    int pontoons;
public:
    /**
     * Requires: nothing
     * Modifies: daysRented, dailyPrice and pontoons
     * Effects: calls parent default constructor and sets pontoons to 2
     */
     Pontoon();


    /**
    * Requires: price of the boat, number of pontoons, name of boat
    * Modifies: name, dailyPrice and pontoons
    * Effects: calls parent default constructor and sets pontoons
    */
    Pontoon(string n, double price, int pontoons);

    /**
    * Requires: days you want the boat, price of the boat, number of pontoons, name of boat
    * Modifies: name, daysRented, dailyPrice and pontoons
    * Effects: calls parent default constructor and sets pontoons
    */
    Pontoon(string n, vector<bool> days, double price, int pontoons);


    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the number of pontoons the boat has
     */
     int getPontoons() const;


    /**
    * Requires: number of pontoons
    * Modifies: pontoons
    * Effects: sets the number of pontoons the boat has to the given value
    */
    void setPontoons(int p);

    /**
   * Requires: nothing
   * Modifies: nothing
   * Effects: Allows you to see how the boats are different
   */
    string extraParts() const override;

};


#endif //M2OEP_EOBRIE17_PONTOON_H
