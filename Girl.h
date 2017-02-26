#ifndef GIRL_H
#define GIRL_H

#include "Gift.h"
#include "Boy.h"
#include <bits/stdc++.h>
using namespace std;

class Boy;
class Gift;

/*! Class of Girl */
class Girl
{
    public:
        /*! Name of Girl */
        string name; 
        /*! Attractiveness of Girl */
        int attractiveness; 
        /*! Maintenance Cost of Girl */
        int maintenance_cost; 
        /*! Intelligence of Girl */
        int intelligence; 
        /*! List of Gifts received from Boyfriend */
        vector <Gift> gifts; 
        /*! Type of Girl */
        string girltype; 
        /*! True if girl is Commited , false Otherwise */
        bool status; 
        /*! Happiness of girl out of relationship */
        double happiness; 
        /*! Boyfriend of girl */
        Boy *bf; 
        
        /*! Constructor for initiallising Girl */
        Girl(string name, int attractiveness, int intelligence, int maintenance_cost, string girltype);
        
        /*! Set Realationship Status of Girl */
        void setStatus(bool inRelationship);

        /*! Return true if Boy meets the dating criterian of Girl*/
        bool canDate(Boy *boy);
        
        /*! Assigns Boyfriend to Girl */
        void assignBoyfriend(Boy *boy);
        
        /*! Calculates Happiness of Girl out of relationship */
        double getHappiness();
};
#endif