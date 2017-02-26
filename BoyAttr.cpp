#include "Boy.h"
#include "Girl.h"
#include "Gift.h"
#include <bits/stdc++.h>
using namespace std;


Boy::Boy(string Name, int Attractiveness, int Intelligence, int Budget, int Min_attraction, string Boytype)
{
    name = Name;
    intelligence = Intelligence;
    attractiveness = Attractiveness;
    budget = Budget;
    min_attraction = Min_attraction;
    boytype = Boytype;
    status = false;
    happiness = 0;
}

void Boy::setStatus(bool inRelationship)
{
    status = inRelationship;
}

bool Boy::canDate(Girl *girl)
{
    if ((girl->attractiveness >= min_attraction) && (girl->maintenance_cost <= budget))
        return true;
    else
        return false;
}

void Boy::assignGirlfriend(Girl *girl)
{
    gf = girl;
}

double Boy::getHappiness()
{
    double happiness;

    map <string,int> enumarate;
    enumarate["Miser"] = 1;
    enumarate["Generous"] = 2;
    enumarate["Geek"] = 3;

    switch (enumarate[boytype])
    {
        case 1 :
            happiness = budget;
            for(int i = 0; i < gifts.size(); i++)
                happiness =  happiness - gifts[i].price;
        break;

        case 2 :
            happiness = gf->getHappiness();
        break;

        case 3 :
            happiness = gf->intelligence;
        break;

        default:
            return -1;
    }
    
    return happiness;
}
