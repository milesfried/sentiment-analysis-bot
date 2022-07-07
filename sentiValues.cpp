//
// Created by Miles Friedman on 6/5/21.
//
#include "tweet.h"
#include "DSString.h"
#include <vector>
#include <iostream>
#include "sentiValues.h"

//constructor
sentiValues::sentiValues(DSString in, DSString in2) {
    value = in;
    id = in2;
}
void sentiValues::print() {
    cout << "Value: " << value << "     ";
    cout << "ID: " << id << endl;
}