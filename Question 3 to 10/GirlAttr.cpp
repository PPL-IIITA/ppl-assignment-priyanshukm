#include "Boy.h"
#include "Girl.h"
#include "Gift.h"
#include <bits/stdc++.h>
using namespace std;


Girl::Girl(string Name, int Attractiveness, int Intelligence, int Maintenance_cost, string Girltype)
{
    name = Name;
    intelligence = Intelligence;
    attractiveness = Attractiveness;
    maintenance_cost = Maintenance_cost;
    girltype = Girltype;
    status = false;
    happiness = 0;
}

void Girl::setStatus(bool inRelationship)
{
    status = inRelationship;
}

bool Girl::canDate(Boy *boy)
{
    if (maintenance_cost <= boy->budget)
        return true;
    else
        return false;
}

void Girl::assignBoyfriend(Boy *boy)
{
    bf = boy;
}

double Girl::getHappiness()
{
    double happiness = 0;

    map <string,int> enumarate;
    enumarate["Choosy"] = 1;
    enumarate["Normal"] = 2;
    enumarate["Desperate"] = 3;

    for(int i = 0; i < gifts.size(); i++)
    {

        switch (enumarate[girltype])
        {
            case 1 :
                happiness += gifts[i].price;
                if (gifts[i].type == "Luxury")
                    happiness += gifts[i].price;
                break;

            case 2 :
                happiness += gifts[i].price + gifts[i].value;
                break;

            case 3 :
                happiness += gifts[i].price;
                break;

            default:
                return -1;
        }
    }
    
    switch (enumarate[girltype])
    {
        case 1 :
            happiness = log10(happiness);
        break;

        case 2 :
        break;

        case 3 :
            happiness = exp(happiness);
        break;
            
        default:
            return -1;
    }
    
    return happiness;
}