//
// Created by Emma O'Brien on 10/2/22.
//

#include "Pontoon.h"
Pontoon::Pontoon():Motorboat(), pontoons(2){
}

Pontoon::Pontoon(string n, double price, int pontoons): Motorboat(n, price), pontoons(pontoons){
}

Pontoon::Pontoon(string n, vector<bool> days, double price, int pontoons): Motorboat(n, days, price), pontoons(pontoons){
}

int Pontoon::getPontoons() const{
    return pontoons;
}

void Pontoon::setPontoons(int p){
    pontoons = p;
}

string Pontoon::extraParts() const{
    return "pontoons";
}