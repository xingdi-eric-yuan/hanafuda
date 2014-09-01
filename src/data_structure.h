#pragma once
#include "general_settings.h"

using namespace std;
///////////////////////////////////
// Card Structures
///////////////////////////////////
struct SingleCard {
    int Flower;
    int Point;
    int Num;
    string Name;
    SingleCard(int a, int b, int c, string d) : Flower(a), Point(b), Num(c), Name(d){}
};


