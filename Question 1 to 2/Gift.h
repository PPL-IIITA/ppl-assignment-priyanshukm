#ifndef GIFT_H
#define GIFT_H

#include <bits/stdc++.h>
using namespace std;

/*! Class of Gifts */
class Gift
{
    public:
    	/*! Name of Gift */
        string name; 
        /*! Type of Gift */
        string type;
        /*! Availability of Gift */
        bool isavailable; 
        /*! Price of Gift */
        int price; 
        /*! Value of Gift */
        int value; 
        /*! Luxury Rating of Luxury Gift Item */
        int Lrating; 
        /*! Difficulty to obtain Luxury Gift */
        int Difficulty; 
        /*! Utility Value of Utility Gifts */
        int Uval; 
        /*! Utility Class of Utility Gifts */
        int Uclass; 

        
        /*! Contructor to initialise Gift */
        Gift(string name, string type, int price, int value, int Lrating, int Difficulty, int Uval, int Uclass);
};
#endif