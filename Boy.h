#ifndef BOY_H
#define BOY_H

#include "Gift.h"
#include "Girl.h"
#include <bits/stdc++.h>
using namespace std;

class Girl;
class Gift;

/* Class for Boy */
class Boy
{
    public:
        string name; /* Name of Boy */
        int attractiveness; /* Attractiveness of Boy */
        int intelligence; /* Intelligence of Boy*/
        int budget; /* Budget of Boy */
        int min_attraction; /* Minimum Attraction Required */ 
        vector <Gift> gifts; /* List of gifts gifted by Boy */
        string boytype; /* Type of Boy */
        bool status; /* True if boy is Commited , false Otherwise */
        double happiness; /* Happiness of boy out of relationship */
        Girl *gf; /* Girlfriend of Boy */
        
        /* Constructor for initiallising Boy */
        Boy(string name, int attractiveness, int intelligence, int budget, int min_attraction, string boytype);
        
        /* Set Realationship Status of Boy */
        void setStatus(bool inRelationship);

        /* Return true if Girl meets the dating criterian of Boy*/
        bool canDate(Girl *girl);

        /* Assigns Girlfriend to Boy */
        void assignGirlfriend(Girl *girl);

        /* Calculates Happiness of Boy out of relationship */
        double getHappiness();
};
#endif