#ifndef GIFT_H
#define GIFT_H

#include <bits/stdc++.h>
using namespace std;

class Gift
{
    public:
        string name; /* Name of Gift */
        string type; /* Type of Gift */
        bool isavailable; /* Availability of Gift */
        int price; /* Price of Gift */
        int value; /* Value of Gift */
        int Lrating; /*Luxury Rating of Luxury Gift Item */
        int Difficulty; /* Difficulty to obtain Luxury Gift */
        int Uval; /* Utility Value of Utility Gifts */
        int Uclass; /*Utility Class of Utility Gifts */
        
        /* Contructor to initialise Gift */
        Gift(string name, string type, int price, int value, int Lrating, int Difficulty, int Uval, int Uclass);
};
#endif