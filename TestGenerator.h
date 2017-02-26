#include <string>
using namespace std;

class TestGenerator {

    public:
		string name; /* Name of Boy, Girl or Gift */
		string type; /* Type of Boy, Girl or Gift */
		int attractiveness; /* Attractiveness of Boy or Girl */
		int budget; /*Budget of Boy */
		int min_attraction; /* Minimum Attractiveness which Boy Demands */
		int intelligence; /* Intelligence of Boy or Girl */
		int maintenance_cost; /* Maintenance cost of Girl */
		int price; /* Price of Gift */
		int value; /* value of Gift */
		int Lrating; /* Luxury Rating of Luxury Gifts */
		int Difficulty; /* Difficulty to obtain Luxury Gifts */
		int Uval; /*Utility Value of Utility Gifts */
		int Uclass; /* Utility Class of Utility Gifts */

		/* Contructor to Invoke Test Generation */
		TestGenerator(int numofboys,int numofgirls,int numofgifts);
		
		/* Generate Random Number between mini and maxi */
		int getRand(int mini, int maxi);
};
