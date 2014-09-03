#pragma once
#include "general_settings.h"

using namespace std;

void init_rules();

void init_cards(vector<int>&, vector<int>& ,vector<int>&,
                vector<int>&, vector<int>&, vector<int>&);

void deal_cards(vector<int>&, vector<int>& ,vector<int>&,
                vector<int>&, vector<int>&, vector<int>&);

void random_move(vector<int>&, vector<int>&, int);

int card_amount(vector<int>&);

void koi_koi(vector<int>&);
