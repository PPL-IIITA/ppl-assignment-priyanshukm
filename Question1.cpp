#include "Readfile.h"
#include "TestGenerator.h"
#include "Boy.h"
#include "Girl.h"
#include "Log.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	TestGenerator test(15,10,50);
	
	vector <Boy> boyslist;
	vector <Girl> girlslist;

	Readfile reader;
	boyslist = reader.ReadBoys();
	girlslist = reader.ReadGirls();


	Log newlog("logfile.txt");

	for(int i = 0; i < boyslist.size(); i++)
	{
		for(int j = 0; j < girlslist.size(); j++)
		{
			if((boyslist[i].status == false && girlslist[j].status == false)
				 && (boyslist[i].canDate(&girlslist[j]) == true && girlslist[j].canDate(&boyslist[i]) == true))
			{
				boyslist[i].status = true;
				girlslist[j].status = true;
				boyslist[i].assignGirlfriend(&girlslist[j]);
				girlslist[j].assignBoyfriend(&boyslist[i]);

				string message = boyslist[i].name + " is Commited to " + girlslist[j].name;
				newlog.logger("Commitment <3 : ",message);

				break;
			}
		} 
	}
	return 0;
}