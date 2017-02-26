#include "Girl.h"
#include "Boy.h"
#include "Gift.h"
#include "Readfile.h"
#include <bits/stdc++.h>

using namespace std;

vector <Boy> Readfile::ReadBoys()  
{
	srand(time(NULL));

	ifstream file;
	file.open("Boys.csv");

	string val,name,type;
	int attractiveness,intelligence,budget,min_attractiveness;
	while (file.good())
	{
		getline(file, val, ';');
		if(val.size() == 0)
			break;
	    name = val;
	    getline(file, val, ';');
	    attractiveness = stoi(val);
	    getline(file, val, ';');
	    intelligence = stoi(val);
	    getline(file, val, ';');
	    budget = stoi(val);
	    getline(file, val, ';');
	    min_attractiveness = stoi(val);
	    getline(file, val, '\n');
	    type = val;
	    Boy bb(name,attractiveness,intelligence,budget,min_attractiveness,type);
	    b.push_back(bb);
	}
	file.close();
	return b;
}

vector <Girl> Readfile::ReadGirls()  
{
	srand(time(NULL));

	ifstream file;
	file.open("Girls.csv");

	string val,name,type;
	int attractiveness,intelligence,maintenance_cost;
	while (file.good())
	{
		getline(file, val, ';');
	    if(val.size() == 0)
			break;
	    name = val;
	    getline(file, val, ';');
	    attractiveness = stoi(val);
	    getline(file, val, ';');
	    intelligence = stoi(val);
	    getline(file, val, ';');
	    maintenance_cost = stoi(val);
	    getline(file, val, '\n');
	    type = val;
	    Girl gg(name,attractiveness,intelligence,maintenance_cost,type);
	    g.push_back(gg);
	}
	file.close();
	return g;
}

vector <Gift> Readfile::ReadGifts()  
{
	srand(time(NULL));

	ifstream file;
	file.open("Gifts.csv");

	string val,name,type;
	int price, value, Lrating, Difficulty, Uval, Uclass ;

	map <string,int> enumarate;
	enumarate["Essential"] = 1;
	enumarate["Luxury"] = 2;
	enumarate["Utility"] = 3;

	while (file.good())
	{
		getline(file, val, ';');
	    if(val.size() == 0)
			break;
	    name = val;
	    getline(file, val, ';');
	    type = val;
	    getline(file, val, ';');
	    price = stoi(val);
	    
	    Gift gii("NULL","NULL",-1,-1,-1,-1,-1,-1);

	    switch (enumarate[type])
		{
			case 1 :
				getline(file, val, '\n');
	    		value = stoi(val);
				gii = Gift(name,type,price,value,-1,-1,-1,-1);
				gi.push_back(gii);
				break;

			case 2 :
				getline(file, val, ';');
	    		value = stoi(val);
				getline(file, val, ';');
	    		Lrating = stoi(val);
				getline(file, val, '\n');
	    		Difficulty = stoi(val);
				gii = Gift(name,type,price,value,Lrating,Difficulty,-1,-1);
				gi.push_back(gii);
				break;
			case 3 :
				getline(file, val, ';');
	    		value = stoi(val);
				getline(file, val, ';');
	    		Uval = stoi(val);
				getline(file, val, '\n');
	    		Uclass = stoi(val);
				gii = Gift(name,type,price,value,-1,-1,Uval,Uclass);
				gi.push_back(gii);
				break;
		}
	}
	file.close();
	return gi;
}