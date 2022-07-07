//
// Created by Miles Friedman on 6/10/21.
//

#ifndef PA01_SENTIMENT_DSVECTOR_H
#define PA01_SENTIMENT_DSVECTOR_H

template<typename T>
class DSVector {
private:
    T* data;
    int size = 0; //# of used spaces
    int capacity = 10;//max # of spaces
    void increase_cap(){
        T* temp = new T[capacity*2];
        for (int i = 0; i < size; i++){
            temp[i] = data[i];
        }
        capacity *= 2;
        delete[] data;
        data = temp;
    }
};


#endif //PA01_SENTIMENT_DSVECTOR_H
