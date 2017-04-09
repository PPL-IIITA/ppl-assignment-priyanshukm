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


	sort(boyslist.begin(),boyslist.end(), [](const Boy& lhs, const Boy& rhs) { return lhs.attractiveness > rhs.attractiveness; });
	sort(girlslist.begin(), girlslist.end(), [](const Girl& lhs, const Girl& rhs) { return lhs.maintenance_cost < rhs.maintenance_cost; });

	int btot = 0,gtot = 0;
	while((btot != boyslist.size()) && (gtot != girlslist.size()))
	{
		int gindex = -1;
		for(int i = 0; i < girlslist.size(); i++)
		{
			if(girlslist[i].status == false)
			{
				gindex = i;
				break;
			}
		}
		if(gindex == -1)
			break;

		int boyfound = 0;
		for(int i = 0;i < boyslist.size(); i++)
		{
			if(boyslist[i].status == false && (boyslist[i].canDate(&girlslist[gindex]) == true && girlslist[gindex].canDate(&boyslist[i]) == true))
			{
				boyslist[i].status = true;
				girlslist[gindex].status = true;
				boyslist[i].assignGirlfriend(&girlslist[gindex]);
				girlslist[gindex].assignBoyfriend(&boyslist[i]);

				string message = boyslist[i].name + " is Commited to " + girlslist[gindex].name;
				newlog.logger("Commitment <3 : ",message);
				boyfound = 1;
				break;
			}
		}
		gtot++;
		if(boyfound)
		{
			btot++;
		}

		
		int bindex = -1;
		for(int i = 0; i < boyslist.size(); i++)
		{
			if(boyslist[i].status == false)
			{
				bindex = i;
				break;
			}
		}
		if(bindex == -1)
			break;

		int girlfound = 0;
		for(int j = 0; j < girlslist.size(); j++)
		{
			if(girlslist[j].status == false && (boyslist[bindex].canDate(&girlslist[j]) == true && girlslist[j].canDate(&boyslist[bindex]) == true))
			{
				boyslist[bindex].status = true;
				girlslist[j].status = true;
				boyslist[bindex].assignGirlfriend(&girlslist[j]);
				girlslist[j].assignBoyfriend(&boyslist[bindex]);
					
				string message = boyslist[bindex].name + " is Commited to " + girlslist[j].name;
				newlog.logger("Commitment <3 : ",message);
				
				girlfound = 1;
				break;
			}
		}
		btot++;
		if(girlfound)
		{
			gtot++;
		}
	}

	sort(giftslist.begin(), giftslist.end(), [](const Gift& lhs, const Gift& rhs){ return lhs.price < rhs.price; });

	newlog.logger("Important : ","Sorted GiftList\n");


	int t = test.getRand(1,30);
	for(int it = 0; it < t; it++)
	{
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

		newlog.logger("Important : ","Gifts Assigned on day" + to_string(it+1) + "\n");

		for(int i = 0; i < boyslist.size(); i++)
		{
			if(boyslist[i].status == true)
			{
				double boyhappiness = boyslist[i].getHappiness();
				double girlhappiness = (boyslist[i].gf)->getHappiness();
				double totHappiness = (boyhappiness + girlhappiness,i);

				if(totHappiness < t)
				{
					//cout<<"totHappiness: "<<totHappiness<<"t: "<<t<<endl;
					boyslist[i].status = false;
					(boyslist[i].gf)->status = false;

					string message = boyslist[i].name + " and " + ((boyslist[i].gf)->name) + " broke up\n";
					newlog.logger("Break Ups : ", message);

					boyslist[i].assignGirlfriend(NULL);
					//(boyslist[i].gf)->bf = NULL;
				}
			}
		}
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
					cout << message << endl;
					newlog.logger("Commitment <3 : ",message);

					break;
				}
			} 
		}
	}

	return 0;
}