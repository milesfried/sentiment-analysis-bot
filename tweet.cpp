//
// Created by Miles Friedman on 6/3/21.
//

#include "tweet.h"
#include <iostream>
#include <vector>

#include "DSString.h"
using namespace::std;

//CONSTRUCTOR
tweet::tweet(DSString in, DSString emo){

     msg = in;
     senti = emo;
}
//setter method for the sentiment
void tweet::setSent(DSString& in) {
    senti = in;
}
//setter method for the msg
void tweet::setMsg(DSString& in) {
    msg = in;
}
//prints the sentiment and the msg of the tweet
void tweet::print(){
    cout << "Sentiment: " << senti << endl;
    cout << "Tweet: " << msg << endl;
}
//prepares the words vector with individual DSString of each word in the tweet
void tweet::tokenMsg(){
    DSString word("");
    int wordCount = 0;
    int tweet_length = msg.getLength();
    for(int i = 0; i < tweet_length; i++){
        //if the char is a space it tokens the word
        if(msg[i] == ' '){
            if(word[msg.getLength() - 1] == 'd' && word[msg.getLength() -2] == 'e' ){
                word[msg.getLength()-2] == '\0';
            }
            if(word[msg.getLength() - 1] == 'g' && word[msg.getLength() - 2] == 'n' && word[msg.getLength() - 3] == 'i'){
                word[msg.getLength()-3] == '\0';
            }
            if(word[msg.getLength() - 1] == 's' && word[msg.getLength() -2] == 'e' ){
                word[msg.getLength()-2] == '\0';

            }
            if(word[msg.getLength() - 1] == 'y' && word[msg.getLength() -2] == 'l' ){
                word[msg.getLength()-2] == '\0';

            }

            words.push_back(word);
            word = "";
            wordCount++;
        }
        //if the char is a letter or the char ' the char is added to the word
        else if(isalpha(msg[i]) || msg[i] == 39){
            word = word + tolower(msg[i]);

        }
        count = wordCount;
    }

}
//prints the individual DSString objects
void tweet::printTokens() {
    for(int i = 0; i < words.size(); i++){
        cout << words.at(i) << endl;
    }
}