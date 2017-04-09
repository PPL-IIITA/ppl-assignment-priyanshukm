#ifndef BOY_H
#define BOY_H

#include "Gift.h"
#include "Girl.h"
#include <bits/stdc++.h>
using namespace std;

class Girl;
class Gift;

/*! Class for Boy */
class Boy
{
    public:
        /*! Name of Boy */
        string name; 
        /*! Attractiveness of Boy */
        int attractiveness; 
        /*! Intelligence of Boy*/
        int intelligence; 
        /*! Budget of Boy */
        int budget; 
        /*! Minimum Attraction Required */ 
        int min_attraction; 
        /*! List of gifts gifted by Boy */
        vector <Gift> gifts; 
        /*! Type of Boy */
        string boytype; 
        /*! True if boy is Commited , false Otherwise */
        bool status; 
        /*! Happiness of boy out of relationship */
        double happiness; 
        /*! Girlfriend of Boy */
        Girl *gf; 
        
        /*! Constructor for initiallising Boy */
        Boy(string name, int attractiveness, int intelligence, int budget, int min_attraction, string boytype);
        
        /*! Set Realationship Status of Boy */
        void setStatus(bool inRelationship);

        /*! Return true if Girl meets the dating criterian of Boy*/
        bool canDate(Girl *girl);

        /*! Assigns Girlfriend to Boy */
        void assignGirlfriend(Girl *girl);

        /*! Calculates Happiness of Boy out of relationship */
        double getHappiness();
};
#endif