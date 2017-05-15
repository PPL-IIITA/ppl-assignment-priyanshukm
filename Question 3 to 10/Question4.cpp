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
	vector <Gift> giftslist;

	Readfile reader;
	boyslist = reader.ReadBoys();
	girlslist = reader.ReadGirls();
	giftslist = reader.ReadGifts();


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

	sort(giftslist.begin(), giftslist.end(), [](const Gift& lhs, const Gift& rhs){ return lhs.price < rhs.price; });

	newlog.logger("Important : ","Sorted GiftList\n");

	for(int i = 0; i < boyslist.size(); i++)
	{
		if(boyslist[i].status == false)
			continue;
		
		int tot = 0;

		map <string,int> enumarate;
		enumarate["Miser"] = 1;
		enumarate["Generous"] = 2;
		enumarate["Geek"] = 3;

		switch (enumarate[boyslist[i].boytype])
		{
			case 1 :
				for(int j = 0;j < giftslist.size(); j++)
				{
					if((giftslist[j].isavailable == true) && (tot + giftslist[j].price < ((boyslist[i].gf)->maintenance_cost)))
					{
						(boyslist[i].gifts).push_back(giftslist[j]);
						((boyslist[i].gf)->gifts).push_back(giftslist[j]);
						tot += giftslist[j].price;
						giftslist[j].isavailable = false;
					}
					else if(giftslist[j].isavailable == true)
					{
						(boyslist[i].gifts).push_back(giftslist[j]);
						((boyslist[i].gf)->gifts).push_back(giftslist[j]);
						tot += giftslist[j].price;
						giftslist[j].isavailable = false;
						boyslist[i].budget = max(boyslist[i].budget,tot);
						break;
					}
				}
				break;
			case 2 :
				for(int j = giftslist.size() - 1;j >= 0; j--)
				{
					if((giftslist[j].isavailable == true) && (tot + giftslist[j].price <= boyslist[i].budget))
					{
						(boyslist[i].gifts).push_back(giftslist[j]);
						((boyslist[i].gf)->gifts).push_back(giftslist[j]);
						tot += giftslist[j].price;
						giftslist[j].isavailable = false;
					}
					else if(giftslist[j].isavailable == true)
					{
						break;
					}
				}
				break;
			case 3 :
				for(int j = 0;j < giftslist.size(); j++)
				{
					if((giftslist[j].isavailable == true) && (tot + giftslist[j].price < ((boyslist[i].gf)->maintenance_cost)))
					{
						(boyslist[i].gifts).push_back(giftslist[j]);
						((boyslist[i].gf)->gifts).push_back(giftslist[j]);
						tot += giftslist[j].price;
						giftslist[j].isavailable = false;
					}
					else if(giftslist[j].isavailable == true)
					{
						(boyslist[i].gifts).push_back(giftslist[j]);
						((boyslist[i].gf)->gifts).push_back(giftslist[j]);
						tot += giftslist[j].price;
						giftslist[j].isavailable = false;
						boyslist[i].budget = max(boyslist[i].budget,tot);
						break;
					}
				}
				int luxurybudgetleft = boyslist[i].budget - tot;
				if(luxurybudgetleft == 0)
					break;
				for(int j = 0; j < giftslist.size(); j++)
				{
					if((giftslist[j].type == "Luxury") && (giftslist[j].isavailable == true) && (giftslist[j].price <= luxurybudgetleft))
					{
						(boyslist[i].gifts).push_back(giftslist[j]);
						((boyslist[i].gf)->gifts).push_back(giftslist[j]);
						tot += giftslist[j].price;
						giftslist[j].isavailable = false;
						break;
					}
				}
				break;
		}
		for(int j = 0; j < (boyslist[i].gifts).size(); j++)
		{
			string message = boyslist[i].name + " Gifted " + ((boyslist[i].gf)->name) + " " + (boyslist[i].gifts)[j].name ;
			cout << message << endl;
			newlog.logger("Gifting : ", message);
		}
	}

	newlog.logger("Important : ","Assigned Gifts\n");

	vector <pair<double, int> > couplehappiness,couplecompatibility;

	int totCouples = 0;

	for(int i = 0; i < boyslist.size(); i++)
	{
		if(boyslist[i].status == true)
		{
			double boyhappiness = boyslist[i].getHappiness();
			double girlhappiness = (boyslist[i].gf)->getHappiness();
			couplehappiness.push_back(make_pair(boyhappiness + girlhappiness,i));

			string message = boyslist[i].name + " and " + ((boyslist[i].gf)->name) + " have " + to_string(boyhappiness + girlhappiness) + " Happiness";
			newlog.logger("Happiness : ", message);

			int costexceed = abs((boyslist[i].budget) - ((boyslist[i].gf)->maintenance_cost));
			int inteldiff = abs((boyslist[i].intelligence) - ((boyslist[i].gf)->intelligence));
			int attrdiff = abs((boyslist[i].attractiveness) - ((boyslist[i].gf)->attractiveness));
			couplecompatibility.push_back(make_pair( costexceed + inteldiff + attrdiff,i));

			message = boyslist[i].name + " and " + ((boyslist[i].gf)->name) + " are " + to_string(costexceed+inteldiff+attrdiff) + " unit Compatible";
			newlog.logger("Compatibility : ", message);

			totCouples++;
		}
	}

	

	sort(couplehappiness.begin(),couplehappiness.end());
	sort(couplecompatibility.begin(),couplecompatibility.end());

	int k = test.getRand(1,totCouples);

	cout<<k<<"Least Happiest Couples : \n";
	for(int i = 0, cur = 0; i < couplehappiness.size() && cur < k; i++, cur++ )
	{
		int index = couplehappiness[i].second;

		cout<<boyslist[index].name<<" and "<<((boyslist[index].gf)->name)<<" broke up!"<<endl;

		(boyslist[index].gf)->status = false;
		((boyslist[index].gf)->gifts).clear();
		((boyslist[index].gf)->bf) = NULL;

		int flag = 0;
		for(int j = 0;j < boyslist.size();j++)
		{
			if((boyslist[j].status == false) && (boyslist[j].canDate((boyslist[index].gf)) == true && 
				(*(boyslist[index].gf)).canDate(&boyslist[j]) == true))
			{
				boyslist[j].status = true;
				(boyslist[index].gf)->status = true;
				boyslist[j].assignGirlfriend(boyslist[index].gf);
				(*(boyslist[index].gf)).assignBoyfriend(&boyslist[j]);

				string message = boyslist[j].name + " is Commited to " + (boyslist[index].gf)->name;
				cout<<message<<endl;
				newlog.logger("Commitment <3 : ",message);
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			cout<<"There is no boy left which fulfills all criteria for being "<<(boyslist[index].gf)->name<<"'s boyfriend\n";

		boyslist[index].status = false;
		(boyslist[index].gifts).clear();
		(boyslist[index].gf) = NULL;
	}
	
	return 0;
}
