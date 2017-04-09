#include <string>
using namespace std;

/* Class to Generate TestCases */
class TestGenerator {

    public:
		/*! Name of Boy, Girl or Gift */
		string name; 
		/*! Type of Boy, Girl or Gift */
		string type; 
		/*! Attractiveness of Boy or Girl */
		int attractiveness; 
		/*! Budget of Boy */
		int budget; 
		/*! Minimum Attractiveness which Boy Demands */
		int min_attraction; 
		/*! Intelligence of Boy or Girl */
		int intelligence; 
		/*! Maintenance cost of Girl */
		int maintenance_cost; 
		/*! Price of Gift */
		int price; 
		/*! value of Gift */
		int value; 
		/*! Luxury Rating of Luxury Gifts */
		int Lrating; 
		/*! Difficulty to obtain Luxury Gifts */
		int Difficulty; 
		/*! Utility Value of Utility Gifts */
		int Uval; 
		/*! Utility Class of Utility Gifts */
		int Uclass; 
		
		/*! Contructor to Invoke Test Generation */
		TestGenerator(int numofboys,int numofgirls,int numofgifts);
		
		/*! Generate Random Number between mini and maxi */
		int getRand(int mini, int maxi);
};
