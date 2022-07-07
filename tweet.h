//
// Created by Miles Friedman on 6/3/21.
//

#ifndef PA01_SENTIMENT_TWEET_H
#define PA01_SENTIMENT_TWEET_H

#include "DSString.h"
#include <vector>
using namespace::std;
class tweet {
private:
    /**
     * private variable declaration
     */
    DSString msg;
    DSString senti;
    vector<DSString> words;
    int count;

public:
    /**
     * Constructor for objects of type tweet.
     * Param One is set to msg
     * Param Two is set to msg
     */
    tweet(DSString, DSString);
    /**
     * @return the DSString senti of the tweet object
     */
    DSString getSent(){ return senti;}
    /**
     * @return the DSString msg of the tweet object
     */
    DSString getMessage(){return msg;}
    /**
     * @return the words vector of the tweet object
     */
    vector<DSString>& getList(){return words;}
    /**
     * @return the integer count of the tweet object
     */
    int getCount(){return count;}
    /**
     * populates the words vector of the tweet object with tokened words
     */
    void tokenMsg();
    /**
     * senti is set to the value of param one
     */
    void setSent(DSString&);
    /**
     * msg is set to the value of param one
     */
    void setMsg(DSString&);
    /**
     * prints the msg and senti
     */
    void print();
    /**
     * prints the individual tokens
     */
    void printTokens();

};
#endif //PA01_SENTIMENT_TWEET_H
