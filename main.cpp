#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <map>
#include "tweet.h"
#include <iomanip>
#include "DSString.h"
#include "sentiValues.h"
using namespace ::std;

map<DSString, int> trainAlg(char *);
vector<sentiValues> testAlg(map<DSString, int> &, char *);
void checkAlg(vector<sentiValues> &, char *, char *);
void sentiFind(int &);

int main(int argC, char *argV[]) {
if(argC > 5) {
    map<DSString, int> wordFreq = trainAlg(argV[1]);

    vector<sentiValues> sentis = testAlg(wordFreq, argV[2]);

    checkAlg(sentis, argV[3], argV[4]);
}
else{
    cout << "Insufficent Input" << endl;
    cout << "See: ./pa01_sentiment <train data> <test data> <test sentiment> <output>" << endl;
}
    return 0;
}
//this function returns a map object that associates words to sentiment
map<DSString, int> trainAlg(char *trainName) {
    vector<tweet> tweetList; //initialize to a big vector
    //buffer cstrings for getline
    char sentiment[500];
    char msg[5000];
    char trash[500];
    fstream file;
    file.open(trainName);
    if (file.is_open()) {
        file.getline(trash, 500);
        //primary read
        file.getline(sentiment, 500, ',');
        //creates a vector filled with tweet objects from the read file
        while (!file.eof()) {
            file.getline(trash, 500, ',');
            file.getline(trash, 500, ',');
            file.getline(trash, 500, ',');
            file.getline(trash, 500, ',');
            file.getline(msg, 5000);
            DSString tempMsg = msg;
            DSString tempSent = sentiment;
            tweetList.push_back(tweet(tempMsg, tempSent));
            file.getline(sentiment, 500, ',');
        }
        map<DSString, int> wordFreq;
        //this builds the map
        for (int i = 0; i < tweetList.size(); i++) {
            tweetList.at(i).tokenMsg();
            for (int l = 0; l < tweetList.at(i).getCount(); l++) {
                DSString curWord = tweetList.at(i).getList().at(l);
                //checks if the word is long enough
                if (curWord.getLength() <= 3) {
                } else {
                    map<DSString, int>::iterator itr = wordFreq.find(curWord);
                    //first positive
                    if (itr == wordFreq.end() && tweetList.at(i).getSent() == "4") {
                        wordFreq[curWord] = 1;
                        //first negative
                    } else if (itr == wordFreq.end() && tweetList.at(i).getSent() == "0") {

                        wordFreq[curWord] = -1;
                        //increment positive
                    } else if (tweetList.at(i).getSent() == "4") {
                        wordFreq[curWord]++;
                        //decrement negative
                    } else {
                        wordFreq[curWord]--;
                    }
                }
            }
        }
        //print the map
        map<DSString, int>::iterator itr;
        for (itr = wordFreq.begin(); itr != wordFreq.end(); ++itr) {
            if (itr->second < -5 || itr->second > 5) {
                //   cout << itr->first << " " << itr->second << endl;
            }
        }
        return wordFreq;
    }
}
//this function returns a vector of sentiValues objects
vector<sentiValues> testAlg(map<DSString, int> &wordFreq, char *classiName) {
    vector<tweet> tweetList;
    fstream file;
    char trash[500];
    char id[500];
    char msg[500];
    int senti = 0;
    file.open(classiName);
    if (file.is_open()) {
        file.getline(trash, 500);
        //primary read
        file.getline(id, 500, ',');
        while (!file.eof()) {
            file.getline(trash, 500, ',');
            file.getline(trash, 500, ',');
            file.getline(trash, 500, ',');
            file.getline(msg, 500);
            tweetList.push_back(tweet(msg, id));
            file.getline(id, 500, ',');
        }
        vector<sentiValues> sentiList;
        //Iterates through all tweets and calculates sentiment value
        for (int l = 0; l < tweetList.size(); l++) {
            senti = 0;
            DSString sentiIn;
            tweetList.at(l).tokenMsg();
            for (int i = 0; i < tweetList.at(l).getCount(); i++) {
                map<DSString, int>::iterator itr = wordFreq.find(tweetList.at(l).getList().at(i));
                if (itr != wordFreq.end()) {
                    sentiFind(itr->second);
                    senti += itr->second;
                }
            }
            if (senti >= 0)
                sentiIn = "4";
            else
                sentiIn = "0";
            sentiList.push_back(sentiValues(sentiIn, tweetList.at(l).getSent()));
        }
//for(int l = 0; l < sentiList.size(); l++){
//    sentiList.at(l).print();
//
//}
        return sentiList;
    }
}
void checkAlg(vector<sentiValues> &sentiList, char *checkName, char *outName) {
    fstream file;
    file.open(checkName);
    vector<sentiValues> sentiList2;
    char sentiment[500];
    char id[5000];
    char trash[500];
    if (file.is_open()) {
        file.getline(trash, 500);
        //primary read
        file.getline(sentiment, 500, ',');
        while (!file.eof()) {
            file.getline(id, 500);
            sentiList2.push_back(sentiValues(sentiment, id));
            file.getline(sentiment, 500, ',');
        }
        double correct = 0.0;
        double total = 0.0;
        vector<DSString> incor;
        for (int i = 0; i < sentiList.size(); i++) {
            for (int l = 0; l < sentiList2.size(); l++) {
                if (sentiList.at(i).getID() == sentiList2.at(l).getID()) {
                    if (sentiList.at(i).getValue() == sentiList2.at(l).getValue()) {
                        correct++;
                    } else {
                        incor.push_back(sentiList.at(i).getID());
                    }
                    total++;
                    i++;
                }
            }
        }
        double accuracy = (correct / total);
//       cout << correct << " correct out of " << total << " total" << endl;
//       cout << accuracy << "% accuracy" << endl;
        ofstream write(outName);
        if (write.is_open()) {
            write << setprecision(3) << accuracy << endl;
            for (int i = 0; i < incor.size(); i++) {
                write << incor.at(i) << endl;
            }
        }

    }
}
void sentiFind(int &senti) {
    if (senti <= -100) {
        senti = -10;
    } else if (senti < -50) {
        senti = -7;
    } else if (senti < -25) {
        senti = -5;
    } else if (senti < -10) {
        senti = -3;
    } else if (senti < 0) {
        senti = -1;
    } else if (senti == 0) {
        senti = 1;
    } else if (senti < 10) {
        senti = 1;
    } else if (senti < 25) {
        senti = 3;
    } else if (senti < 50) {
        senti = 5;
    } else if (senti < 100) {
        senti = 7;
    } else {
        senti = 10;
    }
}