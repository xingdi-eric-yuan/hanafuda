#pragma once
#include "general_settings.h"

using namespace std;

void move_top(vector<SingleCard*> &, vector<SingleCard*> &, int);

void move(vector<SingleCard*> &, vector<SingleCard*> &, int, int);

void reshuffle(	vector<SingleCard*> &,
				vector<SingleCard*> &, 
				vector<SingleCard*> &, 
				vector<SingleCard*> &, 
				vector<SingleCard*> &, 
				vector<SingleCard*> &);