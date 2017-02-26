#include "Gift.h"
#include <bits/stdc++.h>
using namespace std;


Gift::Gift(string Name, string Type, int Price, int Value, int lrating, int difficulty,int uval, int uclass)
{
    name = Name;
    type = Type;
    price = Price;
    value = Value;
    Lrating = lrating;
    Difficulty = difficulty;
    Uval = uval;
    Uclass = uclass;
    isavailable = true;
}