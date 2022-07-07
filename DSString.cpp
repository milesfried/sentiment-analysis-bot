//
// Created by mark on 6/2/2021.
//
using namespace::std;

#include "DSString.h"
//no args constructor
DSString::DSString()
{
    data = new char [1];
    data[0] = '\0';
}
//constructor copies the char*  parameter into the data member variable
/**
 * constructor that accepts char*
 * @param in
 */
DSString::DSString(const char * in) {
    if (in == nullptr){
        data = new char [1];
        data[0] = '\0';
    }
    else {
        data = new char[strlen(in) + 1];
        strcpy(data, in);
    }
}
//constructor copies the DSString parameter into the data member variable
DSString::DSString(const DSString& in){
    data = new char[strlen(in.data) + 1];
    strcpy(data, in.data);
}
 //Overloading stream insertion operator
ostream& operator<< (ostream& out, const DSString& prime){
    out << prime.data;
    return out;
}
//Assignment Operator for char* type
DSString& DSString::operator= (const char* cpy){
    if (this->data == cpy){
        return *this;
    }
    delete[] data;
    data = new char[strlen(cpy) + 1];
    strcpy(data, cpy);
    return *this;
}
//Assignment Operator for DSString type
DSString& DSString::operator= (const DSString& cpy){
    if (this == &cpy){
        return *this;
    }
    delete[] data;
    data = new char[strlen(cpy.data) + 1];
    strcpy(data, cpy.data);
    return *this;
}
//overloading the + operator
DSString DSString::operator+ (const DSString& arg){
    DSString temp;
    temp.data = new char[strlen(data) + strlen(arg.data) + 1];
    strcpy(temp.data, data);
    strcat(temp.data, arg.data);
    return temp;
}
DSString DSString::operator+ (const char* arg){
    DSString temp;
    temp.data = new char[strlen(data) + strlen(arg) + 1];
    strcpy(temp.data, data);
    strcat(temp.data, arg);
    return temp;
}
DSString DSString::operator+ (const char arg){
    DSString temp;
    temp.data = new char[strlen(data)  + 2];
    strcpy(temp.data, data);
    temp[getLength()] = arg;
    temp[getLength() + 1] = '\0';
    return temp;
}
//overloading relational operator for char* type
bool DSString::operator== (const char* arg){
    if (strcmp(data, arg) == 0)
        return true;
    else
        return false;
}
//overloading relational operator for DSString type

bool DSString::operator== (const DSString& arg){
    if (strcmp(data, arg.data) == 0)
        return true;
    else
        return false;
}
//overloading relational operator for char* type
bool DSString::operator> (const char* arg){
    if(strcmp(data, arg) >= 0){
        return true;
    }
    else
        return false;
}
//overloading relational operator for DSString type

bool DSString::operator> (const DSString& arg){
    if(strcmp(data, arg.data) >= 0){
        return true;
    }
    else
        return false;
}
//overloading relational operator for char* type

bool DSString::operator< (const char* arg){
    if(strcmp(data, arg) >= 0){
        return false;
    }
    else
        return true;
}
//overloading relational operator for DSString type

bool DSString::operator< (const DSString& arg){
    if(strcmp(data, arg.data) >= 0){
        return false;
    }
    else
        return true;
}
//overloading relational operator for DSString type
bool DSString::operator< (const DSString& arg) const{
    if(strcmp(data, arg.data) >= 0){
        return false;
    }
    else
        return true;
}
//overloading the [] operator

char& DSString::operator[](const int num){
    return data[num];
}
//returns the length of the string
int DSString::getLength(){
    return strlen(data);
}
//returns a substring of the DSString object
DSString DSString::substring(int& start, int& numChars) {
    char* temp = new char[numChars];
    int l = 0;
    for(int i = start; i < numChars; i++){
        temp[l]= data[i];
        l++;
    }

    DSString back = temp;
    return back;
}
//returns data
char* DSString::c_str() {
    return data;
}