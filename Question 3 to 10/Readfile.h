#include "Girl.h"
#include "Boy.h"
#include "Gift.h"
#include <bits/stdc++.h>
using namespace std;

/*! Class for Reading csv Files */
class Readfile {

    public:
		/*! Store Data of all boys read from File */
		vector <Boy> b; 
		/*! Store Data of all girls read from File */
		vector <Girl> g; 
		/*! Store Data of all gifts read from File */
		vector <Gift> gi; 
		
    	/*! Read Boys.csv to return vector of Boy Objects */
		vector <Boy> ReadBoys();

		/*! Read Girls.csv to return vector of Girl Objects */
		vector <Girl> ReadGirls();

		/*! Read Gifts.csv to return vector of Gift Objects */
		vector <Gift> ReadGifts();
};
