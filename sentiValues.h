//
// Created by Miles Friedman on 6/5/21.
//

#ifndef PA01_SENTIMENT_SENTIVALUES_H
#define PA01_SENTIMENT_SENTIVALUES_H
#include "tweet.h"
#include "DSString.h"
#include <vector>
#include <iostream>


class sentiValues {

private:
    /**
     * private data variable declaration
     */
    DSString value;
    DSString id;
public:
    /**
     * Constructor for type sentiValues.
     * Param One is set to value,
     * Param Two } is set to ID
     */
    sentiValues(DSString, DSString);
    /**
     *
     * @return the value of the sentiValues object
     */
    DSString getValue(){return value;}
    /**
     *
     * @return the id of the sentiValues object
     */
    DSString getID(){return id;}
    /**
     * prints the value and id of the sentiValues object
     */
    void print();
};




#endif //PA01_SENTIMENT_SENTIVALUES_H
