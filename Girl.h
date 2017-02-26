#ifndef GIRL_H
#define GIRL_H

#include "Gift.h"
#include "Boy.h"
#include <bits/stdc++.h>
using namespace std;

class Boy;
class Gift;

/* Class of Girl */
class Girl
{
    public:
        string name; /* Name of Girl */
        int attractiveness; /* Attractiveness of Girl */
        int maintenance_cost; /*Maintenance Cost of Girl */
        int intelligence; /* Intelligence of Girl */
        vector <Gift> gifts; /* List of Gifts received from Boyfriend */
        string girltype; /*Type of Girl */
        bool status; /* True if girl is Commited , false Otherwise */
        double happiness; /* Happiness of girl out of relationship */
        Boy *bf; /* Boyfriend of girl */

        /* Constructor for initiallising Girl */
        Girl(string name, int attractiveness, int intelligence, int maintenance_cost, string girltype);
        
        /* Set Realationship Status of Girl */
        void setStatus(bool inRelationship);

        /* Return true if Boy meets the dating criterian of Girl*/
        bool canDate(Boy *boy);
        
        /* Assigns Boyfriend to Girl */
        void assignBoyfriend(Boy *boy);
        
        /* Calculates Happiness of Girl out of relationship */
        double getHappiness();
};
#endif