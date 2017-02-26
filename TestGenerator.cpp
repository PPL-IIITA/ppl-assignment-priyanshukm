#include "TestGenerator.h"
#include <bits/stdc++.h>

using namespace std;

int TestGenerator:: getRand(int mini, int maxi) {

	int value;
	value = mini + rand()%(maxi - mini + 1);
	return value;

}

TestGenerator::TestGenerator(int numofboys,int numofgirls,int numofgifts)  {

	srand(time(NULL));

	ofstream myfile;
	myfile.open("Boys.csv");

	vector <string> BoyType;
	BoyType.push_back("Miser");
	BoyType.push_back("Generous");
	BoyType.push_back("Geek");

	for (int i = 0; i < numofboys; i++)
	{
		name = "Boy" + to_string(i+1);
		type = BoyType[getRand(0,2)];
		budget = getRand(0,100);
		attractiveness = getRand(0,10);
		intelligence = getRand(0,100);
		min_attraction = getRand(0,10);

		myfile<<name<<";"<<attractiveness<<";"<<intelligence<<";"<<budget<<";"<<min_attraction<<";"<<type<<"\n";
	}
	myfile.close();

	
	/* Generate Girls Data */
	srand(time(NULL));
	myfile.open("Girls.csv");

	vector <string> GirlType;
	GirlType.push_back("Choosy");
	GirlType.push_back("Normal");
	GirlType.push_back("Desperate");

	for (int i = 0; i < numofgirls; i++) {

		name = "Girl" + to_string(i+1);
		type = GirlType[getRand(0,2)];
		attractiveness = getRand(0,10);
		maintenance_cost = getRand(0,100);
		intelligence = getRand(0,100);

		myfile<<name<<";"<<attractiveness<<";"<<intelligence<<";"<<maintenance_cost<<";"<<type<<"\n";


	}
	myfile.close();

	
	/* Generate Gifts Data */
	srand(time(NULL));
	myfile.open("Gifts.csv");

	vector <string> GiftType;
	GiftType.push_back("Essential");
	GiftType.push_back("Luxury");
	GiftType.push_back("Utility");

	map <string,int> enumarate;
	enumarate["Essential"] = 1;
	enumarate["Luxury"] = 2;
	enumarate["Utility"] = 3;

	for (int i = 0; i < numofgifts; i++) {

		name = "Gift" + to_string(i+1);
		type = GiftType[getRand(0,2)];

		price = getRand(1,10);
		value = getRand(1,10);
		
		switch (enumarate[type])
		{
			case 1 :
				myfile<<name<<";"<<type<<";"<<price<<";"<<value<<"\n";
				break;

			case 2 :
				Lrating = getRand(1,10);
				Difficulty = getRand(1,10);
				myfile<<name<<";"<<type<<";"<<price<<";"<<value<<";"<<Lrating<<";"<<Difficulty<<"\n";
				break;
			case 3 :
				Uval = getRand(1,10);
				Uclass = getRand(1,10);
				myfile<<name<<";"<<type<<";"<<price<<";"<<value<<";"<<Uval<<";"<<Uclass<<"\n";
				break;

		}
	}
	myfile.close();

}
